#include<bits/stdc++.h>
using namespace std;

struct ghoomna{
	int r,c;//row and column
};
char player = 'X',opponent = 'O';
bool ghoomnaleft(char Box[3][3]){
	for(int i=0; i<3 ; i++)
	    for(int j=0 ;j<3 ;j++)
	    if(Box[i][j]=='_')
	      return true;
	    else
	      return false;
}
int evaluate(char b[3][3]){
	for(int r = 0; r<3 ; r++){
	    if(b[r][0]==b[r][1] && b[r][1]==b[r][2]){
	      if(b[r][0]==player){
	       return +10;
	      }
	      else if(b[r][0]==opponent)
	       return -10;

	    }
	}
    for(int c = 0 ;c<3 ;c++){
     if(b[0][c]==b[1][c] && b[1][c]==b[2][c]){
       if(b[0][c]==player){
          return +10;
       }
       else if(b[0][c]==opponent)
       return -10;
     }
    }


    	if (b[0][0]==b[1][1] && b[1][1]==b[2][2]) 
	{ 
		if (b[0][0]==player) 
			return +10; 
		else if (b[0][0]==opponent) 
			return -10; 
	} 

	if (b[0][2]==b[1][1] && b[1][1]==b[2][0]) 
	{ 
		if (b[0][2]==player) 
			return +10; 
		else if (b[0][2]==opponent) 
			return -10; 
	} 
}
int minimax(char Box[3][3], int depth, bool isMax) 
{ 
	int score = evaluate(Box); 

	if (score == 10) 
		return score; 
	if (score == -10) 
		return score; 

	if (ghoomnaleft(Box)==false) 
		return 0; 

	if (isMax) 
	{ 
		int best = -1000; 

	
		for (int i = 0; i<3; i++) 
		{ 
			for (int j = 0; j<3; j++) 
			{ 
			
				if (Box[i][j]=='_') 
				{ 
					Box[i][j] = player; 

					best = max( best, 
						minimax(board, depth+1, !isMax) ); 
					Board[i][j] = '_'; 
				} 
			} 
		} 
		return best; 
	} 

	
	else
	{ 
		int best = 1000; 

		
		for (int i = 0; i<3; i++) 
		{ 
			for (int j = 0; j<3; j++) 
			{ 

				if (Box[i][j]=='_') 
				{ 
					
					Box[i][j] = opponent; 

					best = min(best, 
						minimax(Box, depth+1, !isMax)); 

					
					Box[i][j] = '_'; 
				} 
			} 
		} 
		return best; 
	} 
} 
ghoomna bestmove(char Box[3][3]){
  int bestVal = -1000;
  ghoomna bestmov;
  bestmov.r = -1;
  bestmov.c = -1;
for( int i=0 ;i<3 ; i++){
	for(int j=0 ; j<3;j++){
	     if(Box[i][j]=='_'){
	       Box[i][j] = player;
	       int moveval = minimax(Box,0,false);
	       Box[i][j] = '_';
	       if(moveval > bestVal)
	        {
	         bestmov.r=i;
	         bestmov.c=j;
	         bestVal = moveval;
	        }
	     }
	}
}	
cout<<" value of best move is : "<<bestVal<<endl;
return bestmov;  
}
int main() 
{ 
	char Box[3][3] = 
	{ 
		{ 'x', 'o', 'o' }, 
		{ 'o', 'o', 'x' }, 
		{ '_', '_', '_' } 
	}; 

	ghoomna bestMove = bestmov(Box); 

	printf("The Optimal Move is :\n"); 
	printf("ROW: %d COL: %d\n\n", bestMove.r, 
								bestMove.c ); 
	return 0; 
} 