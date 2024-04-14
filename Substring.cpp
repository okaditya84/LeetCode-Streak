int length = seq.length();
    
    bool hasChanges = true;
    while (hasChanges) {
        hasChanges = false;
        for (int i = 0; i < length - 1; ++i) {
            if (seq[i] == 'A' && seq[i + 1] == 'B') {
                seq.erase(i, 2);
                length -= 2;
                hasChanges = true;
                break;
            } else if (seq[i] == 'B' && seq[i + 1] == 'B') {
                seq.erase(i, 2);
                length -= 2;
                hasChanges = true;
                break;
            }
        }
    }
    
    return length;