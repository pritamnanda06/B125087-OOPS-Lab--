// Q6: Document Export System - Virtual function overriding
#include <iostream>
#include <string>
using namespace std;

class Document {
protected:
    string name;
public:
    Document(string n) : name(n) {}
    virtual void exportFile() { cout << "Exporting " << name << endl; }
    virtual ~Document() {}
};

class PDFDocument : public Document {
public:
    PDFDocument(string n) : Document(n) {}
    void exportFile() override { cout << "PDF  export: " << name << ".pdf\n"; }
};

class TextDocument : public Document {
public:
    TextDocument(string n) : Document(n) {}
    void exportFile() override { cout << "Text export: " << name << ".txt\n"; }
};

class CSVDocument : public Document {
public:
    CSVDocument(string n) : Document(n) {}
    void exportFile() override { cout << "CSV  export: " << name << ".csv\n"; }
};

int main() {
    string a, b, c;
    cout << "Enter file names for PDF, Text and CSV documents: ";
    cin >> a >> b >> c;
    PDFDocument p(a); TextDocument t(b); CSVDocument v(c);
    Document* d[] = {&p, &t, &v};
    cout << endl;
    for (Document* x : d) x->exportFile();
}   