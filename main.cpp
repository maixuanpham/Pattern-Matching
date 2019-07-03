//
//  main.cpp
//  Project 3
//
//  Created by Mai Pham on 5/7/18.
//  Copyright © 2018 Mai Pham. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

int BMmatch(const string& text, const string& pattern, int &comp);
vector<int> buildLastFunction(const string& pattern);
int KMPmatch(const string& text, const string& pattern, int &comp);
vector<int> computeFailFunction(const string& pattern);
void printInfor(string type, double comp, double average, double times, int index);

int main(){
    string textUSD, t;
    string textDNA;
    string pattern;
    int bm, kmp, comp;
    double time1, time2, milliSeconds;
    double average;
    
// US Declaration of Independence
    // Input File
    ifstream textFile;
    textFile.open("usdeclarPC.txt");
    if(!textFile.is_open())
        cout << "No text file found. " << endl;
    while (textFile >> t)
        textUSD = textUSD + t + " ";   
    for (int i = 0; i < textUSD.length(); i++)
        textUSD[i] = tolower(textUSD[i]);
    
    // Test Case for USDI
    cout << "Text File: US Declaration of Independence" << endl;
    pattern = "legislation";
    cout << "  Pattern: " << pattern << endl;
    time1 = clock();
    bm = BMmatch(textUSD, pattern, comp);
    time2 = clock();
    milliSeconds = (time2-time1)/CLOCKS_PER_SEC*1000;
    average = comp/(double)pattern.length();
    printInfor("Boyer Moore Algorithm", comp, average, milliSeconds, bm);
    time1 = clock();
    kmp = KMPmatch(textUSD, pattern, comp);
    time2 = clock();
    milliSeconds = (time2-time1)/CLOCKS_PER_SEC*1000;
    average = comp/(double)pattern.length();
    printInfor("Knuth - Morris - Pratt Algorithm", comp, average, milliSeconds, kmp);
    
    pattern = "appealed to their native justice";
    cout << "  Pattern: " << pattern << endl;
    time1 = clock();
    bm = BMmatch(textUSD, pattern, comp);
    time2 = clock();
    milliSeconds = (time2-time1)/CLOCKS_PER_SEC*1000;
    average = comp/(double)pattern.length();
    printInfor("Boyer Moore Algorithm", comp, average, milliSeconds, bm);
    time1 = clock();
    kmp = KMPmatch(textUSD, pattern, comp);
    time2 = clock();
    milliSeconds = (time2-time1)/CLOCKS_PER_SEC*1000;
    average = comp/(double)pattern.length();
    printInfor("Knuth - Morris - Pratt Algorithm", comp, average, milliSeconds, kmp);
    
    pattern = "experimental comparison";
    cout << "  Pattern: " << pattern << endl;
    time1 = clock();
    bm = BMmatch(textUSD, pattern, comp);
    time2 = clock();
    milliSeconds = (time2-time1)/CLOCKS_PER_SEC*1000;
    average = comp/(double)pattern.length();
    printInfor("Boyer Moore Algorithm", comp, average, milliSeconds, bm);
    time1 = clock();
    kmp = KMPmatch(textUSD, pattern, comp);
    time2 = clock();
    milliSeconds = (time2-time1)/CLOCKS_PER_SEC*1000;
    average = comp/(double)pattern.length();
    printInfor("Knuth - Morris - Pratt Algorithm", comp, average, milliSeconds, kmp);
    
    pattern = "in the name";
    cout << "  Pattern: " << pattern << endl;
    time1 = clock();
    bm = BMmatch(textUSD, pattern, comp);
    time2 = clock();
    milliSeconds = (time2-time1)/CLOCKS_PER_SEC*1000;
    average = comp/(double)pattern.length();
    printInfor("Boyer Moore Algorithm", comp, average, milliSeconds, bm);
    time1 = clock();
    kmp = KMPmatch(textUSD, pattern, comp);
    time2 = clock();
    milliSeconds = (time2-time1)/CLOCKS_PER_SEC*1000;
    average = comp/(double)pattern.length();
    printInfor("Knuth - Morris - Pratt Algorithm", comp, average, milliSeconds, kmp);

    
////////////////////////////////////////////////////////////////////////////////////////////
// Human DNA
    // Input File
    ifstream dnaFile;
    dnaFile.open("humanDNA.txt");
    if(!dnaFile.is_open())
        cout << "No text file found. " << endl;
    while (dnaFile >> textDNA)   {}
    
    // Test Cases Human DNA
    cout << "Text File: Human DNA" << endl;
    pattern = "TAGTAC";
    cout << "  Pattern: " << pattern << endl;
    time1 = clock();
    bm = BMmatch(textDNA, pattern, comp);
    time2 = clock();
    milliSeconds = (time2-time1)/CLOCKS_PER_SEC*1000;
    average = comp/(double)pattern.length();
    printInfor("Boyer Moore Algorithm", comp, average, milliSeconds, bm);
    time1 = clock();
    kmp = KMPmatch(textDNA, pattern, comp);
    time2 = clock();
    milliSeconds = (time2-time1)/CLOCKS_PER_SEC*1000;
    average = comp/(double)pattern.length();
    printInfor("Knuth - Morris - Pratt Algorithm", comp, average, milliSeconds, kmp);
    
    pattern = "TGATCTAGA";
    cout << "  Pattern: " << pattern << endl;
    time1 = clock();
    bm = BMmatch(textDNA, pattern, comp);
    time2 = clock();
    milliSeconds = (time2-time1)/CLOCKS_PER_SEC*1000;
    average = comp/(double)pattern.length();
    printInfor("Boyer Moore Algorithm", comp, average, milliSeconds, bm);
    time1 = clock();
    kmp = KMPmatch(textDNA, pattern, comp);
    time2 = clock();
    milliSeconds = (time2-time1)/CLOCKS_PER_SEC*1000;
    average = comp/(double)pattern.length();
    printInfor("Knuth - Morris - Pratt Algorithm", comp, average, milliSeconds, kmp);
    
    pattern = "GAGCAAT";
    cout << "  Pattern: " << pattern << endl;
    time1 = clock();
    bm = BMmatch(textDNA, pattern, comp);
    time2 = clock();
    milliSeconds = (time2-time1)/CLOCKS_PER_SEC*1000;
    average = comp/(double)pattern.length();
    printInfor("Boyer Moore Algorithm", comp, average, milliSeconds, bm);
    time1 = clock();
    kmp = KMPmatch(textDNA, pattern, comp);
    time2 = clock();
    milliSeconds = (time2-time1)/CLOCKS_PER_SEC*1000;
    average = comp/(double)pattern.length();
    printInfor("Knuth - Morris - Pratt Algorithm", comp, average, milliSeconds, kmp);
    
    pattern = "THATCAT";
    cout << "  Pattern: " << pattern << endl;
    time1 = clock();
    bm = BMmatch(textDNA, pattern, comp);
    time2 = clock();
    milliSeconds = (time2-time1)/CLOCKS_PER_SEC*1000;
    average = comp/(double)pattern.length();
    printInfor("Boyer Moore Algorithm", comp, average, milliSeconds, bm);
    time1 = clock();
    kmp = KMPmatch(textDNA, pattern, comp);
    time2 = clock();
    milliSeconds = (time2-time1)/CLOCKS_PER_SEC*1000;
    average = comp/(double)pattern.length();
    printInfor("Knuth - Morris - Pratt Algorithm", comp, average, milliSeconds, kmp);
    
    return 0;
}

void printInfor(string type, double comp, double average, double times, int index)    {
    cout << "\tPattern Matching Type = " << type << endl;
    cout << "\tNumber of Comparisons = " << comp << endl;
    cout << "\tAverage comparisons = " << average << endl;
    cout << "\tTimes = " << times << endl;
    if (index == -1)
        cout << "\tPattern is not in the text." << endl << endl;
    else
        cout << "\tPattern found at = " << index << endl << endl;
}


/** Simplified version of the Boyer-Moore algorithm. Returns the index of
 *  the leftmost substring of the text matching the pattern, or -1 if none.
 */
int BMmatch(const string& text, const string& pattern, int & comp) {
    comp = 0;
    std::vector<int> last = buildLastFunction(pattern);
    int n = text.size();
    int m = pattern.size();
    int i = m - 1;
    if (i > n - 1)                                    // pattern longer than text?
        return -1;                                    // ...then no match
    int j = m - 1;
    do {
        comp++;
        if (pattern[j] == text[i])    {
            if (j == 0) return i;                    // found a match
            else {                                    // looking-glass heuristic
                i--; j--;                            // proceed right-to-left
            }
        }
        else {                                        // character-jump heuristic
            i = i + m - std::min(j, 1 + last[text[i]]);
            j = m - 1;
        }
    } while (i <= n - 1);
    return -1;                                        // no match
}
// construct function last
vector<int> buildLastFunction(const string& pattern) {
    const int N_ASCII = 128;                        // number of ASCII characters
    int i;
    std::vector<int> last(N_ASCII);                  // assume ASCII character set
    for (i = 0; i < N_ASCII; i++)                    // initialize array
        last[i] = -1;
    for (i = 0; i < pattern.size(); i++) {
        last[pattern[i]] = i;                        // (implicit cast to ASCII code)
    }
    return last;
}


// KMP algorithm
int KMPmatch(const string& text, const string& pattern, int & comp) {
    comp = 0;
    int n = text.size();
    int m = pattern.size();
    std::vector<int> fail = computeFailFunction(pattern);
    int i = 0;                                        // text index
    int j = 0;                                        // pattern index
    while (i < n) {
        if (pattern[j] == text[i]) {
            if (j == m - 1)
                return i - m + 1;                    // found a match
            i++;  j++;
        }
        else if (j > 0) j = fail[j - 1];
        else i++;
        comp++;
    }
    return -1;                                        // no match
}
vector<int> computeFailFunction(const string& pattern) {
    std::vector<int> fail(pattern.size());
    fail[0] = 0;
    int m = pattern.size();
    int j = 0;
    int i = 1;
    while (i < m) {
        if (pattern[j] == pattern[i]) {                // j + 1 characters match
            fail[i] = j + 1;
            i++;  j++;
        }
        else if (j > 0)                                // j follows a matching prefix
            j = fail[j - 1];
        else {                                        // no match
            fail[i] = 0;
            i++;
        }
    }
    return fail;
}


