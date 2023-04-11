typedef struct {
    int k;
    int j;
} item;

int comp(item a, item b) {
    if (a.k == b.k) {
        if (a.j < b.j) return -1;
        if (a.j == b.j) return 0;
        if (a.j > b.j) return 1;
    } else {
        if (a.k < b.k) return -1;
        if (a.k > b.k) return 1;
    }
    return 0;
}

int comp(item a, item b) {
    if (a.k == b.k) {
        return b.j - a.j
    } else {
        return b.k - a.k;
    }
}