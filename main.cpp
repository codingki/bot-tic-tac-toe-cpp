#include <iostream>
#include<sstream>

using namespace std;
int pil;

struct box{
    int nomor;
    bool terisi = false;
    int player;
    string value;
}box[10];

bool gameOver = false;
int winner;

struct player1{
    string name;
}player1;

struct player2{
    string name;
}player2;


string toString(int i){
    stringstream a;
    a<<i;
    string b;
    a>>b;
    return b;
}

string playerVal(int player){
    if(player == 1){
        return "X";
    }else if(player == 2){
        return "O";
    }
}

bool playerJalan(int pilihan, int player){
    if(box[pilihan].terisi == true || pilihan < 1 || pilihan > 9){
        return false;
    }else{
        box[pilihan].value = playerVal(player);
        box[pilihan].terisi = true;
        box[pilihan].player = player;
        return true;
    }

}

void selesaiChecker(){
    if(box[1].value == box[2].value && box[2].value == box[3].value){
        winner = box[1].player;
        gameOver = true;
    }else if(box[1].value == box[5].value && box[5].value == box[9].value){
        winner = box[1].player;
        gameOver = true;
    }else if(box[1].value == box[4].value && box[4].value == box[7].value){
        winner = box[1].player;
        gameOver = true;
    }else if(box[2].value == box[5].value && box[5].value == box[8].value){
        winner = box[2].player;
        gameOver = true;
    }else if(box[3].value == box[6].value && box[6].value == box[9].value){
        winner = box[3].player;
        gameOver = true;
    }else if(box[3].value == box[5].value && box[5].value == box[7].value){
        winner = box[3].player;
        gameOver = true;
    }else if(box[4].value == box[5].value && box[5].value == box[6].value){
        winner = box[4].player;
        gameOver = true;
    }else if(box[7].value == box[8].value && box[8].value == box[9].value){
        winner = box[7].player;
        gameOver = true;
    }else if(box[1].terisi == true && box[2].terisi == true && box[3].terisi == true && box[4].terisi == true && box[5].terisi == true && box[6].terisi == true && box[7].terisi == true && box[8].terisi == true && box[9].terisi == true){
        winner = 3;
        gameOver = true;
    }



}

void tampilBox(){
    cout <<endl;
    cout << "|||||||||||||||||||||||" << endl;
    cout << "||     ||     ||     ||" << endl;
    cout << "||  "<<box[1].value<<"  ||  "<<box[2].value<<"  ||  "<<box[3].value<<"  ||" << endl;
    cout << "||     ||     ||     ||" << endl;
    cout << "|||||||||||||||||||||||" << endl;
    cout << "||     ||     ||     ||" << endl;
    cout << "||  "<<box[4].value<<"  ||  "<<box[5].value<<"  ||  "<<box[6].value<<"  ||" << endl;
    cout << "||     ||     ||     ||" << endl;
    cout << "|||||||||||||||||||||||" << endl;
    cout << "||     ||     ||     ||" << endl;
    cout << "||  "<<box[7].value<<"  ||  "<<box[8].value<<"  ||  "<<box[9].value<<"  ||" << endl;
    cout << "||     ||     ||     ||" << endl;
    cout << "|||||||||||||||||||||||" << endl;
    cout <<endl;
}

bool cegahMenang(int i, int j, int k){
    if( ( (box[i].player == 1 && box[j].player == 1) || (box[j].player == 1 && box[k].player == 1) || (box[i].player == 1 && box[k].player == 1) )
       && (box[i].terisi == false || box[j].terisi == false || box[k].terisi == false) ){
        if(playerJalan(i, 2)){
                return true;
            }else if(playerJalan(j, 2)){
                return true;
            }else{
                playerJalan(k, 2);
                return true;
            }
    }else{
        return false;
    }
}
bool botJalan(int i, int j, int k){
    if(box[i].terisi == false || box[j].terisi == false || box[k].terisi == false){
        if(playerJalan(i, 2)){
            return true;
        }else if(playerJalan(j, 2)){
            return true;
        }else{
            playerJalan(k, 2);
            return true;
        }
    }else{
        return false;
    }
}
void bot (){
    if(cegahMenang(1,2,3)){
        return;
    }else if(cegahMenang(1,4,7)){
        return;
    }else if(cegahMenang(1,5,9)){
        return;
    }else if(cegahMenang(2,5,8)){
        return;
    }else if(cegahMenang(3,6,9)){
        return;
    }else if(cegahMenang(3,5,7)){
        return;
    }else if(cegahMenang(4,5,6)){
        return;
    }else if(cegahMenang(7,8,9)){
        return;
    }else if(botJalan(1,2,3)){
        return;
    }else if(botJalan(4,5,6)){
        return;
    }else{
        botJalan(7,8,9);
        return;
    }
}

void game (){
    while(gameOver == false){
        int pilihan;
        if(gameOver == false){
            jalanPlayer1:
            tampilBox();
            cout<<"Giliran "<<player1.name<<" ( X )"<<endl<<"Masukan pilihan : ";
            cin>>pilihan;

            if(playerJalan(pilihan, 1)){
                selesaiChecker();
            }else{
                cout<<"Masukan pilihan yang lain"<<endl;
                goto jalanPlayer1;
            }
        }
        if(gameOver == false){
            if(pil == 1){
                jalanPlayer2:
                tampilBox();
                cout<<"Giliran "<<player2.name<<" ( O )"<<endl<<"Masukan pilihan : ";
                cin>>pilihan;
                if(playerJalan(pilihan, 2)){
                    selesaiChecker();
                }else{
                    cout<<"Masukan pilihan yang lain"<<endl;
                    goto jalanPlayer2;
                }
            }else if(pil == 2){
                tampilBox();
                cout<<"Giliran Bot..."<<endl;
                bot();
                selesaiChecker();
            }
        }
    }
    tampilBox();
}

void pemenang(){
    if(winner == 1){
        cout<<"Pemenangnya adalah : "<<player1.name<<endl;
    }else if(winner == 2){
        cout<<"Pemenangnya adalah : "<<player2.name<<endl;
    }else{
        cout<<"Hasilnya Seri"<<endl;
    }


}

int main()
{

for( int i = 0; i < 10; i++){
    box[i].nomor = i;
    box[i].value = toString(i);
}

    cout<<"Ingin bermain dengan player 2 atau Bot ?"<<endl;
    cout<<"1. Player 2"<<endl;
    cout<<"2. Bot"<<endl;
    cout<<"Masukan Pilihan : ";
    cin>>pil;

    cout<< "Masukan Nama Player 1 : ";
    cin>>player1.name;
    if(pil == 1){
        cout<< "Masukan Nama Player 2 : ";
        cin>>player2.name;
    }else if(pil == 2){
        player2.name = "Bot";
    }

    cout<<endl;
    game();
    cout<<endl;
    cout<<"Game Selesai"<<endl;
    pemenang();

    return 0;
}
