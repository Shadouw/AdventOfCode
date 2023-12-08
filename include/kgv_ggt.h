#pragma once

long long ggT(long long zahl1, long long zahl2)
{
    if (0 == zahl2) {
        return zahl1;
    }

    return ggT(zahl2, zahl1 % zahl2);
}

long long kgV(long long zahl1, long long zahl2)
{
    return (zahl1 * zahl2) / ggT(zahl1, zahl2);
}