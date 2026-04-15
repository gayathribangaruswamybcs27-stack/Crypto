#define TABLE_SIZE 200003

typedef struct Node {
    char *key;
    int count;
    struct Node *next;
} Node;

Node *table[TABLE_SIZE];

unsigned long hash(char *s) {
    unsigned long h = 5381;
    while (*s) {
        h = ((h << 5) + h) + *s;
        s++;
    }
    return h % TABLE_SIZE;
}

char* normalize(char *word) {
    int len = strlen(word);
    char *res = (char*)malloc(len + 1);

    int shift = word[0] - 'a';

    for (int i = 0; i < len; i++) {
        res[i] = ((word[i] - 'a' - shift + 26) % 26) + 'a';
    }

    res[len] = '\0';
    return res;
}

long long countPairs(char** words, int wordsSize) {
    memset(table, 0, sizeof(table));

    long long ans = 0;

    for (int i = 0; i < wordsSize; i++) {
        char *norm = normalize(words[i]);
        unsigned long idx = hash(norm);

        Node *curr = table[idx];
        while (curr) {
            if (strcmp(curr->key, norm) == 0) {
                ans += curr->count;
                curr->count++;
                free(norm);
                norm = NULL;
                break;
            }
            curr = curr->next;
        }

        if (norm) {
            Node *node = (Node*)malloc(sizeof(Node));
            node->key = norm;
            node->count = 1;
            node->next = table[idx];
            table[idx] = node;
        }
    }

    return ans;
}
