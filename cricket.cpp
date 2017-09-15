#include < iostream.h > 
#include < conio.h > 
#include < stdlib.h > 
#include < stdio.h >

int over[5][6], i, j, o_scr = 0, t_scr, copy[2], or_cnt;
char tm_a[15], tm_b[15];
void scr_bd(int k) {
    clrscr();
    t_scr = 0;
    cout << "\n\t\t" << k + 1 << " * INNINGS -> Team ' ";
    if (k == 0) {
        cout << tm_a << " '";
    } else if (k == 1) {
        cout << tm_b << " '";
    }
    for (i = 0; i < or_cnt; i++) {
        cout << "\n" << i + 1 << "* OVER\n\n";
        for (j = 0; j < 6; j++) {
            cout << j + 1 << "* BALL ";
            do {
                cin >> over[i][j];
            } while (over[i][j] > 6);
            o_scr += over[i][j];
        }
        t_scr += o_scr;
        cout << "\n-> " << o_scr << " RUN(s) SCORED IN THIS OVER\n";
        o_scr = 0;
    }
    cout << "\n-> " << t_scr << " RUN(s) SCORED IN " << k + 1 << "* INNINGS";
    copy[k] = t_scr;
    getch();
}

void main() {
    clrscr();
    cout << "\n\n\t\t\tEnter Following";
    cout << "\nOvers         : ";
    cin >> or_cnt;
    cout << "\nTeam 'A' Name : ";
    gets(tm_a);
    cout << "\nTeam 'B' Name : ";
    gets(tm_b);
    for (int k = 0; k < 2; k++) {
        scr_bd(k);
    }
    clrscr();
    cout << "\n\n\n\t\tRESULT : ";
    if (copy[0] > copy[1]) {
        cout << " Team A -> '" << tm_a << "' WON";
    } else if (copy[0] == copy[1]) {
        cout << "MATCH DRAW";
    } else {
        cout << " Team B -> '" << tm_b << "' WINS";
    }
    cout << "\n\n\t\t\t  Score Card\n\n";
    cout << "\t\t    TEAM " << tm_a << "   " << tm_b << "\n";
    cout << "\t\t\tRUNS " << copy[0] << "        " << copy[1];
    getch();
}
