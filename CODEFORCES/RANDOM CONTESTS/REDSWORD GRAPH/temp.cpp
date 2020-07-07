int bishop()
{
    if (r1 == r2 || c1 == c2)
        return 0;

    //upper right
    if (r2 < r1 && c2 > c1)
    {
        //r-- , c++
        while (valid(r1, c1))
        {
            if (r1 == r2 && r2 == c2)
            {
                return 1;
            }
            r1--, c1++;
        }
    }
    else if (r2 < r1 && c2 < c1) //upper left
    {

        while (valid(r1, c1))
        {
            if (r1 == r2 && r2 == c2)
            {
                return 1;
            }
            r1--, c1--;
        }
    }
    else if (r2 > r1 && c2 > c1) //lower right
    {

        while (valid(r1, c1))
        {
            if (r1 == r2 && r2 == c2)
            {
                return 1;
            }
            r1++, c1++;
        }
    }
    else // lower left
    {

        while (valid(r1, c1))
        {
            if (r1 == r2 && r2 == c2)
            {
                return 1;
            }
            r1++, c1--;
        }
    }

    return 0;
}
