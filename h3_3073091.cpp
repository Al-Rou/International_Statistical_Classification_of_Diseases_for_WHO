#include <iostream>
#include <fstream>

using namespace std;

/*********
Task 2
*********/

struct krankHeit
{
    string kodEl;
    string diagEl;
    struct krankHeit *next;
};

/*********
Task 3
*********/

krankHeit* lesFunkMoodle (krankHeit* head, string adresse)
{
    string zeileEin;
    krankHeit* woEl2 = new krankHeit;
    woEl2 = head;
    ifstream einGabeOb;
    einGabeOb.open(adresse);
    if (!einGabeOb.is_open())
    {
        cerr << "Ein Fehler ist beim Eroeffnen der Datei gescheht! Ueberpruefen Sie die Adresse." << endl;
    }
    else
    {
        cout << endl << "Alles hat geklappt. Die Datei ist schon auf." << endl;
        string einGa1, einGa2;
        int k;
            while (getline(einGabeOb, zeileEin))
            {
                einGa1 = "";
                einGa2 = "";
                k = 0;
            while (zeileEin[k] != ';')
            {
                einGa1 = einGa1 + zeileEin[k];
                k++;
            }
            k++;
            while (zeileEin[k] != ';')
            {
                einGa2 = einGa2 + zeileEin[k];
                k++;
            }
            krankHeit* initEl = new krankHeit;
            initEl->kodEl = einGa1;
            initEl->diagEl = einGa2;
            initEl->next = nullptr;
            woEl2->next = initEl;
            woEl2 = woEl2->next;
        }
    einGabeOb.close();
    cout << "Die Liste wurde aufgebaut." << endl;
    cout << "Die Datei ist zugemacht worden!" << endl;
    return head;
    }
}

/*****************************************
Task 4

This function can search even one small
piece of word inside the whole list, however,
for a very large list it collapses!

But I leave it here, because you may tell
me if a better solution for this exists!
*****************************************/

enum suchFeld {K, D, B};


void suchKrankheit (krankHeit* head, string nachEin, suchFeld letEin)
{
    if (letEin == K)
    {
    string suchWort1;
    int kk;
    kk = 0;
    krankHeit* suchTemp = new krankHeit;
    suchTemp = head;
    while (suchTemp != nullptr)
    {
        suchWort1 = "";
        for (int ii = 0; ii < (suchTemp->kodEl.size() - nachEin.size() + 1); ii++)
        {
            for (int jj = ii; jj < ii+nachEin.size(); jj++)
            {
                suchWort1 = suchWort1 + suchTemp->kodEl[jj];
            }

            for (int iiii = 0; iiii < nachEin.size(); iiii++)
            {
                if ((tolower(suchWort1[iiii])!=tolower(nachEin[iiii])))
                {
                    suchWort1 = "";
                    break;
                }
            }
            if (suchWort1 != "")
            {
                kk++;
                cout << endl << kk << ") " << suchTemp->kodEl << endl << "+) " << suchTemp->diagEl << endl;
                break;
            }
        }
        suchTemp = suchTemp->next;
    }
    cout << endl << kk << " Kodes sind gefunden!" << endl;
    }

    else if (letEin == D)
    {
        string suchWort2;
        int kkk;
        kkk = 0;
        krankHeit* suchTemp = new krankHeit;
    suchTemp = head;
    while (suchTemp != nullptr)
        {
            suchWort2 = "";
            for (int iii = 0; iii < (suchTemp->diagEl.size() - nachEin.size() + 1); iii++)
                {
                    for (int jjj = iii; jjj < iii+nachEin.size(); jjj++)
                    {
                        suchWort2 = suchWort2 + suchTemp->diagEl[jjj];
                    }
                    for (int jjjj = 0; jjjj < nachEin.size(); jjjj++)
                        {
                            if ((tolower(suchWort2[jjjj])!=tolower(nachEin[jjjj])))
                                {
                                    suchWort2 = "";
                                    break;
                                }
                        }
                     if (suchWort2 != "")
                        {
                            kkk++;
                            cout << endl << kkk << ") " << suchTemp->kodEl << endl << "+) " << suchTemp->diagEl << endl;
                            break;
                        }
                }
            suchTemp = suchTemp->next;
        }
                cout << endl << kkk << " Diagnosen sind gefunden!" << endl;
    }
}

/***********************************************
This function can search just keywords which
start exactly the same as in the list!

I had to use this, because using the above
function for +70,000 items led into crash!

I leave search lines in the main as comment for
you to check where the problem of my code is.

I think it becomes problematic, because the
above-mentioned function has loops which search
character by character to find every
partially matched item!
***********************************************/

void suchMitKompelet (krankHeit* head, string nachEin, suchFeld letEin)
{
    if (letEin == K)
    {
    string suchWort1;
    int kk;
    kk = 0;
    krankHeit* suchTemp = new krankHeit;
    suchTemp = head;
    while (suchTemp != nullptr)
    {
        suchWort1 = nachEin;

            for (int iiii = 0; iiii < nachEin.size(); iiii++)
            {
                if ((tolower(suchTemp->kodEl[iiii])!=tolower(nachEin[iiii])))
                {
                    suchWort1 = "";
                    break;
                }
            }
            if (suchWort1 != "")
            {
                kk++;
                cout << endl << kk << ") " << suchTemp->kodEl << endl << "+) " << suchTemp->diagEl << endl;
            }
        suchTemp = suchTemp->next;
    }
    cout << endl << kk << " Kodes sind gefunden!" << endl;
    }

    else if (letEin == D)
    {
        string suchWort2;
        int kkk;
        kkk = 0;
        krankHeit* suchTemp = new krankHeit;
        suchTemp = head;
    while (suchTemp != nullptr)
        {
            suchWort2 = nachEin;
                    for (int jjjj = 0; jjjj < nachEin.size(); jjjj++)
                        {
                            if ((tolower(suchTemp->diagEl[jjjj])!=tolower(nachEin[jjjj])))
                                {
                                    suchWort2 = "";
                                    break;
                                }
                        }
                     if (suchWort2 != "")
                        {
                            kkk++;
                            cout << endl << kkk << ") " << suchTemp->kodEl << endl << "+) " << suchTemp->diagEl << endl;
                        }
            suchTemp = suchTemp->next;
        }
                cout << endl << kkk << " Diagnosen sind gefunden!" << endl;
    }
}

void zeigListe (krankHeit* head, int k)
{
    if (head == nullptr){
        cout << "Die Liste ist leer!";
        return;}
    else
    {
            for (int g = 0; g < k; g++){
            cout << (g+1) << ") " << head->kodEl << endl << "+) " << head->diagEl << endl;
            head = head->next;}
        return;
    }
}

int wieGr (krankHeit* head)
{
    int i = 0;
    if (head == nullptr)
        return i;
    else
    {
        do
        {
            i++;
            head = head->next;
        } while (head != nullptr);
        return i;
    }
}

/*************************************
This function was used in the
program to put the list in order!
**************************************/

krankHeit* editHeadListeFunk (krankHeit* head)
{
    krankHeit* editTemp1 = new krankHeit;
    editTemp1 = head;
    head = editTemp1->next;
    delete editTemp1;
    return head;
}

/*********
Task 5
*********/

int main()
{
    krankHeit* head2 = new krankHeit;
    head2->kodEl = "Hallo,";
    head2->diagEl = "Hallo!";
    head2->next = nullptr;
    cout << "Hallo!" << endl << "Dieses Programm kann Ihre .csv Datei einlesen und eine Liste so aufbauen, dass"
    << endl << "Sie einen Kode oder eine Diagnose suchen koennen." << endl;
    cout << "Um es zu ueberpruefen, typen Sie einfach die Adresse der Datei hier: ";
    string nehmAdresse;
    cin >> nehmAdresse;
    head2 = lesFunkMoodle(head2, nehmAdresse);
    head2 = editHeadListeFunk(head2);
    head2 = editHeadListeFunk(head2);
    cout << endl << "Die Liste ist nun vorbereitet!" << endl;
         do
            {
                cout << endl << "Was moechten Sie jetzt machen?"
                << endl << "0) Rausgehen?" << endl << "1) Suchen wie im Moodle?"
                << endl << "2) Ganze Liste?" << endl << "3) Wie viele Elemente?" << endl;
                int p;
                cin >> p;
                if (p == 0)
                {
                    return 0;
                }
                else if (p == 1)
               {
                    cout << "Typen Sie Ihr Schluesselwort: ";
                    string kilidGir;
                    cin >> kilidGir;
                    cout << "Wo wird gesucht?"
                    << endl << "Unter (K)odes, (D)iagnosen, oder (B)eiden?"
                    << endl << "Typen Sie einfach einen Buchstaben: ";
                    char fgH;
                    cin >> fgH;
                    if ((fgH != 'K') && (fgH != 'k') && (fgH != 'D') && (fgH != 'd') && (fgH != 'B') && (fgH != 'b'))
                    {
                        cout << "Falscher Buchstabe!" << endl;
                    }
                    else
                    {
                        if ((fgH == 'K') || (fgH == 'k'))
                            //suchKrankheit(head2, kilidGir, K);
                            suchMitKompelet(head2, kilidGir, K);
                        if ((fgH == 'D') || (fgH == 'd'))
                            //suchKrankheit(head2, kilidGir, D);
                            suchMitKompelet(head2, kilidGir, D);
                        if ((fgH == 'B') || (fgH == 'b'))
                        /*{
                            suchKrankheit(head2, kilidGir, K);
                            suchKrankheit(head2, kilidGir, D);
                        }*/
                            {suchMitKompelet(head2, kilidGir, K);
                            suchMitKompelet(head2, kilidGir, D);}
                    }
                }
                else if (p == 2)
                {
                    zeigListe(head2, wieGr(head2));
                }
                else if (p == 3)
                {
                    cout << wieGr(head2) << endl;
                }
                else
                {
                    cout << "Falsche Zahl!" << endl;
                }
            } while (0 != 1);
}
