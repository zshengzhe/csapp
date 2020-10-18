//
// Created by Zhang Shengzhe on 2020/9/22.
//

/**
 * 3.5
 */
void decode1(long *xp, long *yp, long *zp)
{
    long x = *xp;
    long y = *yp;
    long z = *zp;
    *yp = x;
    *zp = y;
    *xp = z;
}