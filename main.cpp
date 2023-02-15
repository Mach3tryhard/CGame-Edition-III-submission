#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Pozitie{
    int i,j;
}iep;

bool GameOn;
long long m[13][15];
double cost,mutari,punctaj,suma,mutarieficiet=168,powert,powerm;

/// Game Stuff
void IncepereaJocului()
{
    powert=0;
    punctaj=0;
    suma=0;
    mutari=0;
    cost=0;
    powerm=0;
    GameOn=true;
    iep.i=1;iep.j=1;
    for(int i=1;i<=12;i++)
    {
        for(int j=1;j<=14;j++)
        {
            m[i][j]=200+(rand()%(500-200+1));
            suma+=m[i][j];
        }
    }
}
void Afisare()
{
    m[1][1]=0;
    for(int i=1;i<=12;i++)
    {
        for(int j=1;j<=14;j++)
        {
            if(i==iep.i && j==iep.j)
            {
                cout<<"^o^ ";/// personajul
            }
            else
            {
                if(m[i][j]==0)
                    cout<<"000 ";
                else
                if(m[i][j]==-1)
                    cout<<"TNL ";
                else
                if(m[i][j]==-2)
                    cout<<"ZTN ";
                else
                if(m[i][j]==-3)
                    cout<<"PMC ";
                else
                    cout<<m[i][j]<<' ';
            }
        }
        cout<<'\n';
    }
}
bool GradinaEsteDefrisata()
{
    for(int i=1;i<=12;i++)
    {
        for(int j=1;j<=14;j++)
        {
            if(m[i][j]!=0)
            {
                return false;
            }
        }
    }
    return true;
}
void TransformaComanda(string &s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            s[i]=tolower(s[i]);
        }
    }
}

bool minigame()
{
    int nr;
    system("cls");
    int a=1+(rand()%(100-1+1)),b=1+(rand()%(100-1+1));
    cout<<"Spiritul cel poznas vrea sa iti dea o provocare!\nDaca reusiti sa bateti provocarea o sa puteti sa face tunelul!\n";
    cout<<"Spiritul: Trebuie sa completezi corect aceasta intrebare de matematica! Altfel nu te las in pace!\n";
    cout<<"Cat face "<<a<<" + "<<b<<"= ";
    cin>>nr;
    if(nr==a+b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void functieEnd()
{
    punctaj=double(cost/mutari)*(double (cost/suma))+powerm*10;
    cout<<"Numarul de plantatii folosite este de:"<<powerm<<"\n";
    cout<<"Numarul de tunele folosite este de:"<<powert<<"\n";
    cout<<"Punctajul dumneavoastra este :"<<punctaj<<"\n";
    cout<<"Puteti incerca sa obineti un punctaj mai mare data viitoare!\n";
    cout<<"Daca doriti sa jucati din nou folositi comanda: again\n";
}

/// Game Stuff

///Zona cu Mutari
void MutareS()
{
    if(iep.j>1)
    {
        iep.j--;
        if(m[iep.i][iep.j]!=-1 && m[iep.i][iep.j]!=-2 && m[iep.i][iep.j]!=0 && m[iep.i][iep.j]!=-3)
        {
            cost+=m[iep.i][iep.j];
            m[iep.i][iep.j]=0;
        }
        mutari++;
        Afisare();
    }
    else
    {
        Afisare();
        cout<<"\nVa aflati la marginea gradinii! Nu puteti sa va mutati spre stanga!\n";
    }
}
void MutareD()
{
    if(iep.j<14)
    {
        iep.j++;
        if(m[iep.i][iep.j]!=-1 && m[iep.i][iep.j]!=-2 && m[iep.i][iep.j]!=0 && m[iep.i][iep.j]!=-3)
        {
            cost+=m[iep.i][iep.j];
            m[iep.i][iep.j]=0;
        }
        mutari++;
        Afisare();
    }
    else
    {
        Afisare();
        cout<<"\nVa aflati la marginea gradinii! Nu puteti sa va mutati spre dreapta!\n";
    }
}
void MutareSUS()
{
    if(iep.i>1)
    {
        iep.i--;
        if(m[iep.i][iep.j]!=-1 && m[iep.i][iep.j]!=-2 && m[iep.i][iep.j]!=0 && m[iep.i][iep.j]!=-3)
        {
            cost+=m[iep.i][iep.j];
            m[iep.i][iep.j]=0;
        }
        mutari++;
        Afisare();
    }
    else
    {
        Afisare();
        cout<<"\nVa aflati la marginea gradinii! Nu puteti sa va mutati in sus!\n";
    }
}
void MutareJOS()
{
    if(iep.i<12)
    {
        iep.i++;
        if(m[iep.i][iep.j]!=-1 && m[iep.i][iep.j]!=-2 && m[iep.i][iep.j]!=0 && m[iep.i][iep.j]!=-3)
        {
            cost+=m[iep.i][iep.j];
            m[iep.i][iep.j]=0;
        }
        mutari++;
        Afisare();
    }
    else
    {
        Afisare();
        cout<<"\nVa aflati la marginea gradinii! Nu puteti sa va mutati in jos!\n";
    }
}

void MutareT(char c)
{
    if(c=='a')
    {
        bool ocupat=false;
        for(int i=iep.i;i<=iep.i+3;i++)
        {
            for(int j=iep.j;j>=iep.j-3;j--)
            {
                if(m[i][j]==-1 || m[i][j]==-2 || m[i][j]==-3)
                    ocupat=true;
            }
        }
        if(iep.i<10 && iep.j>3 && ocupat==false)
        {
            for(int i=iep.i;i<=iep.i+3;i++)
            {
                for(int j=iep.j;j>=iep.j-3;j--)
                {
                    m[i][j]=-2;
                }
            }
            for(int l=1;l<=3;l++)
            {
                iep.i++;
                iep.j--;
                m[iep.i][iep.j]=-1;
            }
            mutari++;
            Afisare();
            powert++;
        }
        else
        {
            system("cls");
            Afisare();
            cout<<"\nVa aflati la marginea gradinii sau exista deja ceva in acea zona! Nu puteti sapa tunel in acea directie!\n";
        }
    }
    if(c=='e')
    {
        bool ocupat=false;
        for(int i=iep.i;i>=iep.i-3;i--)
        {
            for(int j=iep.j;j<=iep.j+3;j++)
            {
                if(m[i][j]==-1 || m[i][j]==-2 || m[i][j]==-3)
                    ocupat=true;
            }
        }
        if(iep.i>3 && iep.j<12 && ocupat==false)
        {
            for(int i=iep.i;i>=iep.i-3;i--)
            {
                for(int j=iep.j;j<=iep.j+3;j++)
                {
                    m[i][j]=-2;
                }
            }
            for(int l=1;l<=3;l++)
            {
                iep.i--;
                iep.j++;
                m[iep.i][iep.j]=-1;
            }
            mutari++;
            Afisare();
            powert++;
        }
        else
        {
            system("cls");
            Afisare();
            cout<<"\nVa aflati la marginea gradinii sau exista deja ceva in acea zona! Nu puteti sapa tunel in acea directie!\n";
        }
    }
    if(c=='q')
    {
        bool ocupat=false;
        for(int i=iep.i;i>=iep.i-3;i--)
        {
            for(int j=iep.j;j>=iep.j-3;j--)
            {
                if(m[i][j]==-1 || m[i][j]==-2 || m[i][j]==-3)
                    ocupat=true;
            }
        }
        if(iep.i>3 && iep.j>3 && ocupat==false)
        {
            for(int i=iep.i;i>=iep.i-3;i--)
            {
                for(int j=iep.j;j>=iep.j-3;j--)
                {
                    m[i][j]=-2;
                }
            }
            for(int l=1;l<=3;l++)
            {
                iep.i--;
                iep.j--;
                m[iep.i][iep.j]=-1;
            }
            mutari++;
            Afisare();
            powert++;
        }
        else
        {
            system("cls");
            Afisare();
            cout<<"\nVa aflati la marginea gradinii sau exista deja ceva in acea zona! Nu puteti sapa tunel in acea directie!\n";
        }
    }
    if(c=='d')
    {
        bool ocupat=false;
        for(int i=iep.i;i<=iep.i+3;i++)
        {
            for(int j=iep.j;j<=iep.j+3;j++)
            {
                if(m[i][j]==-1 || m[i][j]==-2 || m[i][j]==-3)
                    ocupat=true;
            }
        }
        if(iep.i<10 && iep.j<12 && ocupat==false)
        {
            for(int i=iep.i;i<=iep.i+3;i++)
            {
                for(int j=iep.j;j<=iep.j+3;j++)
                {
                    m[i][j]=-2;
                }
            }
            for(int l=1;l<=3;l++)
            {
                iep.i++;
                iep.j++;
                m[iep.i][iep.j]=-1;
            }
            mutari++;
            powert++;
            Afisare();
        }
        else
        {
            system("cls");
            Afisare();
            cout<<"\nVa aflati la marginea gradinii sau exista deja ceva in acea zona! Nu puteti sapa tunel in acea directie!\n";
        }
    }
}

void MutareM(char c)
{
    if(c=='a')
    {
        bool ocupat=false;
        for(int i=iep.i;i<=iep.i+3;i++)
        {
            for(int j=iep.j;j>=iep.j-3;j--)
            {
                if(m[i][j]==-1 || m[i][j]==-2 || m[i][j]==-3)
                    ocupat=true;
            }
        }
        if(iep.i<10 && iep.j>3 && ocupat==false)
        {
            for(int i=iep.i;i<=iep.i+3;i++)
            {
                for(int j=iep.j;j>=iep.j-3;j--)
                {
                    m[i][j]=-3;
                }
            }
            mutari++;
            Afisare();
            powerm++;
        }
        else
        {
            system("cls");
            Afisare();
            cout<<"\nVa aflati la marginea gradinii sau exista deja ceva in acea zona! Nu puteti planta in acea directie!\n";
        }
    }
    if(c=='e')
    {
        bool ocupat=false;
        for(int i=iep.i;i>=iep.i-3;i--)
        {
            for(int j=iep.j;j<=iep.j+3;j++)
            {
                if(m[i][j]==-1 || m[i][j]==-2 || m[i][j]==-3)
                    ocupat=true;
            }
        }
        if(iep.i>3 && iep.j<12 && ocupat==false)
        {
            for(int i=iep.i;i>=iep.i-3;i--)
            {
                for(int j=iep.j;j<=iep.j+3;j++)
                {
                    m[i][j]=-3;
                }
            }
            mutari++;
            Afisare();
            powerm++;
        }
        else
        {
            system("cls");
            Afisare();
            cout<<"\nVa aflati la marginea gradinii sau exista deja ceva in acea zona! Nu puteti planta in acea directie!\n";
        }
    }
    if(c=='q')
    {
        bool ocupat=false;
        for(int i=iep.i;i>=iep.i-3;i--)
        {
            for(int j=iep.j;j>=iep.j-3;j--)
            {
                if(m[i][j]==-1 || m[i][j]==-2 || m[i][j]==-3)
                    ocupat=true;
            }
        }
        if(iep.i>3 && iep.j>3 && ocupat==false)
        {
            for(int i=iep.i;i>=iep.i-3;i--)
            {
                for(int j=iep.j;j>=iep.j-3;j--)
                {
                    m[i][j]=-3;
                }
            }
            mutari++;
            Afisare();
            powerm++;
        }
        else
        {
            system("cls");
            Afisare();
            cout<<"\nVa aflati la marginea gradinii sau exista deja ceva in acea zona! Nu puteti planta in acea directie!\n";
        }
    }
    if(c=='d')
    {
        bool ocupat=false;
        for(int i=iep.i;i<=iep.i+3;i++)
        {
            for(int j=iep.j;j<=iep.j+3;j++)
            {
                if(m[i][j]==-1 || m[i][j]==-2 || m[i][j]==-3)
                    ocupat=true;
            }
        }
        if(iep.i<10 && iep.j<12 && ocupat==false)
        {
            for(int i=iep.i;i<=iep.i+3;i++)
            {
                for(int j=iep.j;j<=iep.j+3;j++)
                {
                    m[i][j]=-3;
                }
            }
            mutari++;
            powerm++;
            Afisare();
        }
        else
        {
            system("cls");
            Afisare();
            cout<<"\nVa aflati la marginea gradinii sau exista deja ceva in acea zona! Nu puteti planta in acea directie!\n";
        }
    }
}

///Zona cu Mutari

/// Zona cu dialog
void DialogT()
{
    cout<<"\nFelicitari, ati reusit sa scapati de spirit!\n";
    Afisare();
    cout<<"Utilizati inca o comanda pentru a alege directia tuneului:\n";
    cout<<"|\nv <- pentru diagonala stanga jos folositi comanda: a\n";
    cout<<"|\nv -> pentru diagonala dreapta jos folositi comanda: d\n";
    cout<<"^\n| <- pentru diagonala stanga sus folositi comanda: q\n";
    cout<<"^\n| -> pentru diagonala dreapta sus folositi comanda: e\n";
}

void DialogM()
{
    Afisare();
    cout<<"Utilizati inca o comanda pentru a alege directia plantatiei:\n";
    cout<<"|\nv <- pentru diagonala stanga jos folositi comanda: a\n";
    cout<<"|\nv -> pentru diagonala dreapta jos folositi comanda: d\n";
    cout<<"^\n| <- pentru diagonala stanga sus folositi comanda: q\n";
    cout<<"^\n| -> pentru diagonala dreapta sus folositi comanda: e\n";
}

void Cutscene()
{
    cout<<"Iepurasul Bocanila incepe din coltul de stanga sus al gradinii sale.\nCand acesta trece printr-o pozitie, o defriseaza.\n";
    cout<<"Ajutati-l sa defriseze cat mai eficient gradina lui si sa isi planteze morcovi pe care sa ii manance.\n";
}

void DialogEnd()
{
    cout<<"Jocul a fost incheiat!\nAti avut costul de defrisare de :"<<cost<<"\nNumarul de mutari folosite per total a fost de :"<<mutari<<"\n";
}

void DialogComandaGresita()
{
    cout<<"\nAceasta comanda nu exista! \nVa rugam sa incercati din nou utilizand comanda help daca nu stiti o comanda. \n";
}

void DialogHelp()
{
    cout<<"\nAceasta este lista de comenzi pe care le poate face Iepurasul Bocanila: \n";
    cout<<"\nIepurasul se poate muta -> \n stanga folosind comanda: a \n dreapta folosind comanda: d \n sus folosind comanda: w \n jos folosind comanda: s \n";
    cout<<"\nAcesta poate sa faca -> \n tunel folosing comanda: t \n plantatie folosing comanda: p \n\n";
    cout<<"Daca doriti sa terminati jocul si sa aflati scorul dumneavoastra, utilizati comanda: end \n";
    cout<<"Daca doriti sa incepeti un joc nou, utilizati comanda: again \n";
    cout<<"Daca doriti sa opriti aplicatia, utilizati comanda: exit \n";
}

/// Zona cu dialog

int main()
{
    /// Lucruri de inceput
    Cutscene();
    IncepereaJocului();
    Afisare();
    cout<<"Pentru o lista cu toate mutarile posibile, va rugam sa introduceti help. \n";
    cout<<"Va rog introduceti urmatoarea mutare:";
    while(GameOn)
    {
        string mutare;
        cin>>mutare;
        TransformaComanda(mutare);
        if(mutare=="help")
        {
            system("cls");
            DialogHelp();
        }
        else
        if(mutare=="a")
        {
            system("cls");
            MutareS();
        }
        else
        if(mutare=="d")
        {
            system("cls");
            MutareD();
        }
        else
        if(mutare=="s")
        {
            system("cls");
            MutareJOS();
        }
        else
        if(mutare=="w")
        {
            system("cls");
            MutareSUS();
        }
        else
        if(mutare=="t")
        {
            if(minigame()==true)
            {
                if(powert<3)
                {
                    system("cls");
                    DialogT();
                    string comanda2;
                    cin>>comanda2;
                    system("cls");
                    TransformaComanda(comanda2);
                    if(comanda2=="a")
                        MutareT('a');
                    else
                    if(comanda2=="d")
                        MutareT('d');
                    else
                    if(comanda2=="q")
                        MutareT('q');
                    else
                    if(comanda2=="e")
                        MutareT('e');
                    else
                        DialogComandaGresita();
                }
                else
                {
                    cout<<"\nAti folosit cele 3 tunele pe care le aveati la dispozitie!Incercati altceva!\n";
                }
            }
            else
            {
                cout<<"\nNu ai batut provocarea spiritul! Va rugam sa incercati din nou utilizand comanda :t\n";
            }
        }
        else
        if(mutare=="p")
        {
            if(powerm<4)
            {
                system("cls");
                DialogM();
                string comanda2;
                cin>>comanda2;
                system("cls");
                TransformaComanda(comanda2);
                if(comanda2=="a")
                    MutareM('a');
                else
                if(comanda2=="d")
                    MutareM('d');
                else
                if(comanda2=="q")
                    MutareM('q');
                else
                if(comanda2=="e")
                    MutareM('e');
                else
                    DialogComandaGresita();
            }
            else
            {
                cout<<"\nAti folosit cele 4 plantatii pe care le aveati la dispozitie!Incercati altceva!\n";
            }
        }
        else
        if(mutare=="end")
        {
            system("cls");
            DialogEnd();
            functieEnd();
        }
        else
        if(mutare=="again")
        {
            system("cls");
            Cutscene();
            IncepereaJocului();
            Afisare();
            cout<<"Pentru o lista cu toate mutarile posibile, va rugam sa introduceti help. \n";
            cout<<"Va rog introduceti urmatoarea mutare:";
        }
        else
        if(mutare=="exit")
        {
            GameOn=false;
            break;
        }
        else
        {
            system("cls");
            DialogComandaGresita();
        }
    }
    return 0;
}
