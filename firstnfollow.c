
#include <stdio.h>

int main()
{
    printf("FIRST SETS\n");

    printf("FIRST(E)  = { (, id }\n");
    printf("FIRST(E') = { +, epsilon }\n");
    printf("FIRST(T)  = { (, id }\n");
    printf("FIRST(T') = { *, epsilon }\n");
    printf("FIRST(F)  = { (, id }\n");

    printf("\nFOLLOW SETS\n");

    printf("FOLLOW(E)  = { ), $ }\n");
    printf("FOLLOW(E') = { ), $ }\n");
    printf("FOLLOW(T)  = { +, ), $ }\n");
    printf("FOLLOW(T') = { +, ), $ }\n");
    printf("FOLLOW(F)  = { *, +, ), $ }\n");

    return 0;
}



E  → T E'
E' → + T E' | ε
T  → F T'
T' → * F T' | ε
F  → ( E ) | id

output :

FIRST SETS
FIRST(E)  = { (, id }
FIRST(E') = { +, epsilon }
FIRST(T)  = { (, id }
FIRST(T') = { *, epsilon }
FIRST(F)  = { (, id }

FOLLOW SETS
FOLLOW(E)  = { ), $ }
FOLLOW(E') = { ), $ }
FOLLOW(T)  = { +, ), $ }
FOLLOW(T') = { +, ), $ }
FOLLOW(F)  = { *, +, ), $ }