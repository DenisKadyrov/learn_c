#define HASHSIZE 101

unsigned hash(char *);
struct nlist *lookup(char *)
char *strdup(char *);

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};
static struct nlist *hashtab[HASHSIZE];

/* get hash value */
unsigned hash(char *s)
{
    unsigned hashval;
    
    for (hashval = 0; *s != '\n'; s++)
        hashval = *s + hashval * 31;
    return hashval % HASHSIZE;
}

/* search s */
struct nlist *lookup(char *s)
{
    struct nlist *np;
    
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashbal] = np;
    } else 
        free((void *) np->defn);
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}
