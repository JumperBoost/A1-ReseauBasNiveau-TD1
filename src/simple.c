#include <stdio.h>

#define MESSAGE "Super\n"

struct Personne {
    char *nom;
    int age;
    float taille;
};

struct Famille {
    char *nom;
    struct Personne pere;
    struct Personne mere;
    int nb_enfants;
    struct Personne *enfants;
};

float x;
char carac, *mot;
int entier, tab[10];

int multiplication(int a, int b) {
    return a * b;
}

int longueurChaine(char *chaine) {
    int i = 0;
    while (chaine[i] != '\0')
        i++;
    return i-1;
}

int palindrome(char *s) {
    int longueur_s = longueurChaine(s);
    for(int i = 0; i < longueur_s/2; i++)
        if(s[i] != s[longueur_s-1-i])
            return 0;
    return 1;
}

int age_total(struct Famille *f) {
    int nbMax = f->nb_enfants;
    int ageTotal = f->mere.age + f->pere.age;
    for(int i = 0; i < nbMax; i++)
        ageTotal += f->enfants[i].age;
    return ageTotal;
}

int main() {
    printf(MESSAGE);
    printf("Quel est la multiplication de 2x3 ?\n");
    printf("2x3 = %i\n", multiplication(2, 3));

    tab[0] = 1;
    tab[1] = tab[0] + 3;
    printf("Valeur de tab[1] = %i\n", tab[1]);
    printf("a: %i, b: %i, c: %i\n", tab[0], tab[1], tab[2]);

    char* msg = "Youpi\n";  // 'Youpi\n' fait 7 octets (5 pour 'Youpi', 1 pour '\n', 1 pour '\0' (marquant la fin d'un champ de caractère)
    printf("%s\n", msg);

    // -------------------

    int a, *b;
    a = 12;
    b = &a;
    printf("La valeur de b est %i.\n", *b);
    a = 6;
    printf("La valeur de b est %i.\n", *b);
    *b = a * 3;
    printf("La valeur de b est %i.\n", *b);

    int t[2];
    t[0] = 13;
    t[1] = 76;
    printf("Premiere adresse: %lu,\nseconde adresse: %lu\n",
           (long unsigned) t,
           (long unsigned) (t+1));  // t est l'adresse mémoire de la 1re valeur, t+1 est l'adresse mémoire de la 2nd valeur (4 octets suivant la 1re adresse)
    printf("%lu\n", t[0]);
    printf("%lu\n", *(t+1));


    int x = 5;
    if(x > 6) {
        printf("x est > 6.\n");
    } else if(x <= 4) {
        printf("x est <= 4\n");
    } else {
        printf("4 < x <= 6;\n");
    }

    switch (x) {
        case 3:
            printf("x est egale a 3.\n");
            break;

        case 5:
            printf("x est egale a 5.\n");
            break;

        default:
            printf("x n'est pas dans la liste.\n");
            break;
    }

    // Afficher tous les nombres de 1 à 100
    for(int i = 0; i < 100; i++)
        printf("Chiffre %i.\n", i+1);

    // Afficher tous les nombres de 1 à 100 non multiple de 3 et 7
    for(int i = 0; i < 100; i++)
        if(i % 3 > 0 && i % 7 > 0)
            printf("Chiffre %i non multiple de 3 et 7.\n", i);

    char chaine[80];
    printf("Entrez une chaine: ");
    fgets(chaine, 80, stdin);
    fputs(chaine, stdout);

    printf("La longueur de la chaine precedente est de longueur %i.\n", longueurChaine(chaine));
    printf("Le mot %s est un palindrome ? %i\n", chaine, palindrome(chaine));

    // Types et structures
    struct Personne p1;
    p1.nom = "Thomas";
    p1.age = 25;
    p1.taille = 1.87;
    printf("La personne s'appelle %s, a %i ans, et mesure %fm.\n", p1.nom, p1.age, p1.taille);

    printf("Taille | chaine: %i, entier: %i, flottant: %i, personne: %i\n",
           sizeof (char*),
           sizeof (int),
           sizeof (float),
           sizeof (struct Personne));

    struct Personne p2;
    p2.nom = "Clara";
    p2.age = 26;
    p2.taille = 1.82;

    struct Personne p3;
    p3.nom = "Paul";
    p3.age = 2;
    p3.taille = 0.86;

    struct Famille f;
    f.nom = "Degusta";
    f.pere = p1;
    f.mere = p2;
    f.nb_enfants = 1;
    struct Personne enf[f.nb_enfants];
    enf[0] = p3;
    f.enfants = enf;
    printf("La famille %s a comme pere %s, comme mere %s avec %i enfant(s).\n", f.nom, f.pere.nom, f.mere.nom, f.nb_enfants);
    printf("L'age total des membres de la famille est de %i.\n", age_total(&f));
    printf("Taille | famille: %i ; max attendue: %i\n", sizeof (struct Famille),
           sizeof (char*) + sizeof (struct Personne) * 2 + sizeof (int) * f.nb_enfants + sizeof (struct Personne[f.nb_enfants]));
    return 0;
}