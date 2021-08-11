#include<iostream>
#include<cstring>
using namespace std;

double leapDays[12] = {31,29,31,30,31.30,31,31,30,31,30,31};
double nonLeapDays[12] = {31,28,31,30,31.30,31,31,30,31,30,31};

char weeks[7][3] = {{'s','u','n'},
                    {'m','o','n'},
                    {'t','u','e'},
                    {'w','e','d'},
                    {'t','h','u'},
                    {'f','r','i'},
                    {'s','a','t'}};

void swap(int &a, int &b){
    a=a+b;
    b=a-b;
    a=a-b;
}

int abs(int a){
    if(a<0) return -a;
    return a;
}

int nLeaps(int y1, int y2){
    if(y2<y1) swap(y1,y2);
    return (y2/4-y1/4)-(y2/100-y1/100)+(y2/400-y1/400);
}

// sunday monday tuesday wednesday thursday friday saturday
class Date{
public:
    int dd, mm, yyyy;

    Date(int d, int m, int y){
        dd= d;
        mm= m;
        yyyy= y;
    }

    int operator-(Date d){
        int ans= (d.yyyy-yyyy)*365 + nLeaps(d.yyyy, yyyy);
        d.yyyy= yyyy;
        int m=d.mm;
        double* days;
        
        if((yyyy%4 == 0 && yyyy%100 != 0) || yyyy%400 ==0) days = leapDays;
        else days = nonLeapDays;
        if(yyyy%4 == 0 && d.mm == 1) ans--;
        while(d.mm != mm){
            if(d.mm < mm) ans -= days[d.mm-2];
            else ans += days[d.mm-1];
            d.mm += (-d.mm+mm)/abs(d.mm-mm);
        }
        ans += d.dd - dd;
        return ans;
    }
};

class Calendar{
public:
    int year, month, weekIndex;
    int horizontal[6][7]={0}, vertical[7][6]={0};

    void fillCalendar(){
        for(int i=0; i<7; i++){
            horizontal[0][i] = i+1;
            vertical[i][0] = i+1;
        }
        double* days;
        if((year%4==0 && year%100!=0) || year%400==0) days = leapDays;
        else days = nonLeapDays;
        int p = weekIndex, q=1;
        for(int i=1; i<=days[month-1]; i++){
            horizontal[q][p]=i;
            vertical[p][q]=i;

            p++;
            if(p==7){
                p=0;
                q++;
            }
        }
    }

    void display(){
        for(int i=0; i<6; i++){
            for(int j=0; j<7; j++)
            {
                if(horizontal[i][j]<10){ 
                    if(i==0){
                        cout << weeks[j][0] << weeks[j][1] << weeks[j][2] << " ";
                    }
                    else cout << horizontal[i][j] << "   ";
                    
                }
                else cout << horizontal[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;
        for(int i=0; i<7; i++){
            for(int j=0; j<6; j++){
                if(vertical[i][j]<10){ 
                    if(j==0){
                        cout << weeks[i][0] << weeks[i][1] << weeks[i][2] << " ";
                    }
                    else cout << vertical[i][j] << "   ";
                    
                }
                else cout << vertical[i][j] << "  ";
            }
            cout << endl;
        }
    }

    Calendar(int m, int y){
        month = m;
        year = y;
    }

    void FindDay(){
        Date d1(1,month,year), d2(11,8,2021);
        int ans;
        if(d2.yyyy>d1.yyyy || (d2.yyyy == d1.yyyy && d2.mm>d1.mm) || (d2.yyyy==d1.yyyy && d2.mm==d1.mm && d2.dd>d1.dd)){
            ans = d1-d2;
            weekIndex = (10-ans%7)%7;
        }
        else {
            ans=d2-d1;
            weekIndex = (3+(ans%7))%7;
        }
    }
};

int main(){
    Calendar c(11,2003);
    c.FindDay();
    c.fillCalendar();
    c.display();
}