void kmpPreprocess() {
    int i = 0, j = -1;
    b[0] = -1;                           // starting values
    
    while (i < m) {                      // pre-process P
        while ((j >= 0) && (P[i] != P[j])) {
            j = b[j];                    // different, reset j (the fallback)
        }
        ++i; 
        ++j;
        b[i] = j;                        // same, advance both and record
    }
}

void kmpSearch() {
    int i = 0, j = 0;                            // starting values
    
    while (i < n) {                              // search through T
        while ((j >= 0) && (T[i] != P[j])) {
            j = b[j];                            // if different, reset j using the cheat sheet
        }
        
        ++i; 
        ++j;                                     // if same, advance both pointers
        
        if (j == m) {                            // a match is found
            j = b[j];                            // prepare j for the next potential match
        }
    }
}
