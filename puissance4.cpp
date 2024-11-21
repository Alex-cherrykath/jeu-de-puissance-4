       #include<iostream>
 #include<stdlib.h>
 #include<string>

//declaration des objets a utiliser

    void print_grid(int grid[7][6]);
    bool valid_column(int grid[7][6], int column , int player );
    int option;
    int score1 = 0;
    int score2=0;
    int c,l;
    int winner;

int main (int argc, char**argv){

    int grid[7][6]={};
    std::string choix;

    int player = 1;
    print_grid(grid);

    std::cout<<"1. Joueur vs Joueur\n";
    std::cout<<"2. Joueur vs IA\n";
    std::cin>> option;

    switch(option){

        // Joueur1 vs Joueur2
        case 1 :

            while(true){

                std::cout<<"Joueur_"<<player<<"--> colonne:";
                std::cin>> choix;

                if (choix=="exit"){
                    break;
                }
                
                bool success= false;

                if(choix.size()==1){

                    if(choix[0]>='0' && choix[0]<='7'){

                        int col = choix[0]-'0';
                        success=valid_column(grid, col, player);
                    }

                }

                system("CLS");

                if(!success){

                    std::cout<<"Votre choix est invalide Veuillez rejouer!\n";
                }
                else{

                    if (player==1){

                        player=2;
                    }
                    else{

                        player=1;
                    }
                }

                // Possibilites du joueur 1 de gagner

                for (c=0; c<6; c++){

                    for(l=0; l<5; l++){

                        if(grid[c][l]==1){

                            if(grid[c][l+1]==1){

                                if(grid[c][l+2]==1){

                                    if(grid[c][l+3]==1){

                                        winner=1;
                                    }

                                }
                            }
                            else if(grid[c+1][l]==1){

                                if(grid[c+2][l]==1){

                                    if(grid[c+3][l]==1){

                                        winner=1;
                                    }
                                    
                                }

                            }
                            else if(grid[c+1][l+1]==1){

                                if(grid[c+2][l+2]==1){

                                    if(grid[c+3][l+3]==1){

                                        winner=1;
                                    }
                                    
                                }

                            }
                        else if(grid[c-1][l]==1){

                                if(grid[c-2][l]==1){

                                    if(grid[c-3][l]==1){

                                        winner=1;
                                    }
                                    
                                }
                            }
                        else if(grid[c][l-1]==1){

                                if(grid[c][l-2]==1){

                                    if(grid[c][l-3]==1){

                                        winner=1;
                                    }
                                    
                                }

                            }
                        else if(grid[c-1][l-1]==1){

                                if(grid[c-2][l-2]==1){

                                    if(grid[c-3][l-3]==1){

                                        winner=1;
                                    }
                                    
                                }
                            }
                        }
                    }
                } 

                // Possibilite du joueur 2 de gagner
  
                for (c=0; c<6; c++){

                    for(l=0; l<5; l++){

                        if(grid[c][l]==2){

                            if(grid[c][l+1]==2){

                                if(grid[c][l+2]==2){

                                    if(grid[c][l+3]==2){

                                        winner=2;
                                    }

                                }
                            }
                            else if(grid[c+1][l]==2){

                                if(grid[c+2][l]==2){

                                    if(grid[c+3][l]==2){

                                        winner=2;
                                    }
                                    
                                }

                            }
                            else if(grid[c+1][l+1]==2){

                                if(grid[c+2][l+2]==2){

                                    if(grid[c+3][l+3]==2){

                                        winner=2;
                                    }
                                    
                                }

                            }
                        else if(grid[c-1][l]==2){

                                if(grid[c-2][l]==2){

                                    if(grid[c-3][l]==2){

                                        winner=2;
                                    }
                                    
                                }
                            }
                        else if(grid[c][l-1]==2){

                                if(grid[c][l-2]==2){

                                    if(grid[c][l-3]==2){

                                        winner=2;
                                    }
                                    
                                }

                            }
                        else if(grid[c-1][l-1]==2){

                                if(grid[c-2][l-2]==2){

                                    if(grid[c-3][l-3]==2){

                                        winner=2;
                                    }
                                    
                                }
                            }
                        }
                    }
                } 
                
                print_grid(grid);

                if(winner!=0){

                    break;
                }
            }

            std::cout<<"le gagnant est le joueur_"<<winner<<"Felicitation\n";

        
        //ici on doit implementer l'ia

        case 2:
            break;
        }

        return 0;

    }

//afficher la grille

void print_grid(int grid[7][6]){
    for (int ligne = 0; ligne < 6; ligne++){
        std::cout << "|";
        for (int col = 0; col < 7; col++){
            if (grid[col][ligne] == 1){
                std::cout << "\033[31m*\033[37m";
            } else 
            if (grid[col][ligne] == 2){
                std::cout << "\033[32m*\033[37m";
            }
            else {
                std::cout << "\033[37m*\033[37m";
            }
            std::cout << "|";
        }
        std::cout << "\n";
    }
}

bool valid_column(int grid[7][6], int column , int player ){
    for (int line = 5 ; line >= 0; line--){
        if (grid[column - 1][line] == 0){
            grid[column - 1][line] = player;
            return true;
        }
    }
    return false;
}