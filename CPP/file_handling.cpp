#include <iostream>     // has declaration of istream and ostream classes
#include <fstream>      // has ifstream, ofstream and fstream class declaration
#include <string>       // for getline()
using namespace std;

//    ----------ios------------
//    |                       |
// istream --------------- ostream
//    |           |           |
// ifstream    iostream    ofstream
//    |           |           |
//    |        fstream        |
// istream_withassign      ostream_withassign
// (predefined object is cin)         (predefined object is cout)

// ios -> input-output-stream-class
// istream -> input-stream  -> extraction operator >> is defined in istream class.
// ostream -> output-stream -> insertion operator << is defined in ostream class.
// ifstream -> input-file-stream
// ofstream -> output-file-stream
// iostream -> input-output-stream -> just a combination of istream and ostream nothing more
// fstream -> input-output-file-stream          -> added feature of input-output to file



// output stream -> data flows in stream from program to file(or console). Make an object of <ofstream> class to represent the output stream(linked with program to file).
// input stream -> data flows in stream from file(or console) to program. Make an object of <ifstream> class to represent the input stream(linked with file to program).



int main() {
    ofstream fout;      // made an object of ofstream. fout -> file output. cout -> console output.
    // This acts like a pipe between program and file to be written. We write in the file using this object.
    // Hence it must be linked with that specific file now.

    // fout.open("sample.txt");    // if sample.txt does not exist, then it'll be created.
    // fout << "helloo baby\n";    // writes to the file
    // fout << "What you doing tonight?";
    // fout.close();               // only after calling close(), the file is closed and written back in hard-disk. Until close is not called, all the writing in the file is in RAM.
    
    
    ifstream fin("sample.txt");          // made an object of ifstream and opened and linked with file also(constructor overloading of ifstream). fin -> file input. cin -> console input.
    // This acts like a pipe between file to be read and program. We read from the file using this object.
    // Hence it must be linked with that specific file now.
    char c;
    cout << "1. Using fin >> c extraction => ";
    while(!fin.eof()) {     // scan each character from file until end-of-file(eof) is reached.
        fin >> c;           // space, tab, newline are ignored while scanning(delimiters), hence such characters are never scanned in char c.
        cout << c;          // display the scanned character on console.
    }
    fin.close();

    fin.open("sample.txt");
    cout << "\n2. Using c = fin.get() extraction => ";
    while(!fin.eof()) {
        c = fin.get();      // get() does not considers space, tab or newline as delimiters(hence are properly scanned in c).
        cout << c;
    }
    fin.close();

    string s;
    fin.open("sample.txt");
    cout << "\n3. Using fin >> s extraction => ";
    while(fin >> s) {           // scans each word/string one by one until nothing else to scan from file. Just like cin >> s scans string from console.
        cout << s << "***";
    }
    fin.close();

    fin.open("sample.txt");
    cout << "\n4. Using getline(fin, s) extraction => ";
    while(getline(fin, s)) {    // scans each line(ignores tab, space) in s. Like getline(cin, s) for scanning whole line from console input.
        cout << s << "###";
    }
    cout << '\n';
    
    // int x;
    // while(cin >> x) {        // keep scanning until the end
    //     cout << x << '\n';
    // }


    // OPENING MODES
    ofstream fout1("sample.txt", ios::app | ios::in);   // multiple input modes. But it won't make sence to use ios::in with ofstream as ios::in is to read the file not write.
    fout1 << "\nLet us go to restaurant";

    return 0;
}

// File Opening Modes
// ios::in     input/read       Open a file for reading.
// ios::out    output/write     Open a file for writing. Deletes pre-written content
// ios::app    append           Does not deletes pre-written content, but appends on it further
// ios::ate    update           Open a file for output and move the read/write control to the end of the file.
// ios::binary binary           For opening binary files.

