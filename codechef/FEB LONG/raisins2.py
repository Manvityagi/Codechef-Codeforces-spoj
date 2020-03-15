'''
N * M <= 2 ** 10 = 1024
to be able to move pieces, 2 <= N and 2 <= M
therefore, N and M must be in the list of divisors (factors of W and H below 1024 // 2),
and N * M <= 2 ** 10
strategy:
we cut into N and M
for each piece, we determine shortest distance of raisins from all sides of the piece
we select the adequate side of the cake (with longest distance)
we move the N or M pieces to that side that have the furthest distance (i.e largest area)
(we assume raisins are distributed randomly and there are no tricky situation)
'''

MAXIMUM = 2 ** 10

def moveleftright(N, M, distancesright, distancesleft, bestareaoverall, otherdistance):
    # determine which side (left or right) would have the most area
    alldistancesleft, alldistancesright = [], []
    bestarea, bestmoves = -1, []
    for x in range(N):
        for y in range(M):
            alldistancesleft.append((distancesleft[y][x], x, y))
            alldistancesright.append((distancesright[y][x], x, y))
    alldistancesright = sorted(alldistancesright, key=lambda x:x[0], reverse=True)
    bestdistanceright = sum(alldistancesright[:M][0])
    alldistancesleft = sorted(alldistancesleft, key=lambda x:x[0], reverse=True)
    bestdistanceleft = sum(alldistancesleft[:M][0])
    if bestdistanceright >= bestdistanceleft:
        bestpieces = [(x, y) for (d, x, y) in alldistancesright[:M]]
        # we move all M bestpieces to right
        if bestdistanceright * otherdistance > bestareaoverall:
            bestarea = bestdistanceright * otherdistance
            bestmoves = []
            # record the moves necessary to move all M bestpieces to right (in same order)
            for i in range(M):
                x, y = bestpieces[i]
                # move (x, y) to (N - 1, M - 1 - i)
                if x == N - 1:
                    bestmoves.append([1, y]) # r -> x becomes 0
                    for k, pieces in enumerate(bestpieces):
                        if pieces[1] == y:
                            bestpieces[k] = [(pieces[0] + 1) % N, y]
                    x = 0
                if y != M - 1 - i:
                    delta = ((M - 1 - i) + M - y) % M
                    for j in range(delta):
                        bestmoves.append([2, x]) # c
                    for k, pieces in enumerate(bestpieces):
                        if pieces[0] == x:
                            bestpieces[k] = [x, (pieces[1] + delta) % M]
                    y = M - 1 - i
                delta = N - 1 - x
                for j in range(delta):
                    bestmoves.append([1, y]) # r
                for k, pieces in enumerate(bestpieces):
                    if pieces[1] == y:
                        bestpieces[k] = [(pieces[0] + delta) % N, y]
    else:
        bestpieces = [(x, y) for (d, x, y) in alldistancesleft[:M]]
        # we move all M bestpieces to left
        if bestdistanceleft * otherdistance > bestareaoverall:
            bestarea = bestdistanceleft * otherdistance
            bestmoves = []
            # record the moves necessary to move all M bestpieces to left (in same order)
            for i in range(M):
                x, y = bestpieces[i]
                # move (x, y) to (0, M - 1 - i)
                if x == 0:
                    bestmoves.append([1, y]) # r -> x becomes 1
                    for k, pieces in enumerate(bestpieces):
                        if pieces[1] == y:
                            bestpieces[k] = [(pieces[0] + 1) % N, y]
                    x = 1
                if y != M - 1 - i:
                    delta = ((M - 1 - i) + M - y) % M
                    for j in range(delta):
                        bestmoves.append([2, x]) # c
                    for k, pieces in enumerate(bestpieces):
                        if pieces[0] == x:
                            bestpieces[k] = [x, (pieces[1] + delta) % M]
                    y = M - 1 - i
                delta = N - x
                for j in range(delta):
                    bestmoves.append([1, y]) # r
                for k, pieces in enumerate(bestpieces):
                    if pieces[1] == y:
                        bestpieces[k] = [(pieces[0] + delta) % N, y]
    return bestarea, bestmoves


def movetopbottom(N, M, distancestop, distancesbottom, bestareaoverall, otherdistance):
    # determine which side (top or bottom) would have the most area
    alldistancestop, alldistancesbottom = [], []
    bestarea, bestmoves = -1, []
    for x in range(N):
        for y in range(M):
            alldistancestop.append((distancestop[y][x], x, y))
            alldistancesbottom.append((distancesbottom[y][x], x, y))
    alldistancestop = sorted(alldistancestop, key=lambda x:x[0], reverse=True)
    bestdistancetop = sum(alldistancestop[:N][0])
    alldistancesbottom = sorted(alldistancesbottom, key=lambda x:x[0], reverse=True)
    bestdistancebottom = sum(alldistancesbottom[:N][0])
    if bestdistancetop >= bestdistancebottom:
        bestpieces = [(x, y) for (d, x, y) in alldistancestop[:N]]
        # we move all N bestpieces to top
        if bestdistancetop * otherdistance > bestareaoverall:
            bestarea = bestdistancetop * otherdistance
            bestmoves = []
            # record the moves necessary to move all N bestpieces to top (in same order)
            # TODO......

    else:
        bestpieces = [(x, y) for (d, x, y) in alldistancesbottom[:N]]
        # we move all N bestpieces to bottom
        if bestdistancebottom * otherdistance > bestareaoverall:
            bestarea = bestdistancebottom * otherdistance
            bestmoves = []
            # record the moves necessary to move all N bestpieces to bottom (in same order)
            # TODO......

    return bestarea, bestmoves

def solve(W, H, R, raisins):
    # 720720 has 100 divisors between 2 and 504 (included) and TLE occurs
    divisorsW = [3]#[d for d in range(2, MAXIMUM // 2 + 1) if W % d == 0]
    divisorsH = [3]#[d for d in range(2, MAXIMUM // 2 + 1) if H % d == 0]

    divisorsW = [28, 30, 33, 35]
    divisorsH = [28, 30, 33, 35]
    
    bestareaoverall = -float("inf")
    bestmovesoverall = []
    bestN, bestM = 1, 1
    for N in divisorsW:
        NN = W // N  # width of 1 piece
        for M in [d for d in divisorsH if d * N <= MAXIMUM]:
            MM = H // M  # height of 1 piece
            distancestop = [[MM + 1] * N for column in range(M)]    # distance of closest raisin to the top of the piece
            distancesbottom = [[MM + 1] * N for column in range(M)] # distance of closest raisin to the bottom of the piece
            distancesleft = [[NN + 1] * N for column in range(M)]   # distance of closest raisin to the left of the piece
            distancesright = [[NN + 1] * N for column in range(M)]  # distance of closest raisin to the right of the piece
            for Xi, Yi in raisins:
                # the raisin is in square (x, y):
                x = Xi // NN
                y = Yi // MM
                # distances to the sides of the piece
                bottom = Yi % MM
                top = MM - bottom
                left = Xi % NN
                right = NN - left
                distancestop[y][x] = min(distancestop[y][x], top)
                distancesbottom[y][x] = min(distancesbottom[y][x], bottom)
                distancesleft[y][x] = min(distancesleft[y][x], left)
                distancesright[y][x] = min(distancesright[y][x], right)
            # we can move N pieces to the top or the bottom of the cake
            '''
            otherdistance = NN
            bestarea, bestmoves = movetopbottom(N, M, distancestop, distancesbottom, bestareaoverall, otherdistance)
            if bestarea > -1 and len(bestmoves) <= MAXIMUM:
                bestareaoverall, bestmovesoverall = bestarea, bestmoves
                bestN, bestM = N, M
            '''
            # we can move M pieces to the right or the left of the cake
            otherdistance = MM
            bestarea, bestmoves = moveleftright(N, M, distancesright, distancesleft, bestareaoverall, otherdistance)
            if bestarea > -1 and len(bestmoves) <= MAXIMUM:
                bestareaoverall, bestmovesoverall = bestarea, bestmoves
                bestN, bestM = N, M
    Q = len(bestmovesoverall)
    print(bestN, bestM, Q)
    for move in bestmovesoverall:
        # note: index base 1 for the problem
        print(move[0], move[1] + 1)

if _name_ == "_main_":
    W, H, R = list(map(int, input().strip().split()))
    raisins = []
    for i in range(R):
        Xi, Yi = list(map(int, input().strip().split()))
        raisins.append((Xi, Yi))
    solve(W, H, R, raisins)