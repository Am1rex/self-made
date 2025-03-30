#include<stdio.h>
#define MAX_SIZE 25  //這個值是可以調的 但建議不要調到30以上




char board[MAX_SIZE][MAX_SIZE];
int SIZE;
void initializeBoard(){  //確認棋盤大小
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			board[i][j]=' ';
		}
	}
}
void printBoard() {  //印出棋盤
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%c", board[i][j]);
            if (j < SIZE - 1) {
                printf(" | ");  //直線
            }
        }
        printf("\n");

        if (i < SIZE - 1) {
            for (int j = 0; j < SIZE - 1; ++j) {
                printf("----");  //橫線
            }
            printf("--\n");
        }
    }
}
int isBoardFull(){  //確認棋盤空間
	for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
            	return 0;
            }
        }
    }
    return 1;
}

int checkWin(char player) {  //確認勝者
  for (int i = 0; i < SIZE; ++i) {
    // 檢查行
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player && board[i][SIZE-2] == player && board[i][SIZE-1] == player) {
      return 1;
    }

    // 檢查列
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player && board[SIZE-2][i] == player && board[SIZE-1][i] == player) {
      return 1;
    }
  }

  // 檢查主對角線
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player && board[SIZE-2][SIZE-2] == player && board[SIZE-1][SIZE-1] == player) {
    return 1;
  }

  // 檢查副對角線
  if (board[0][SIZE-1] == player && board[1][SIZE-2] == player && board[2][SIZE-3] == player && board[SIZE-2][1] == player && board[SIZE-1][0] == player) {
    return 1;
  }

  return 0;
}

int isValidMove(int row, int col) {  //錯誤輸入
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}
int main() {  //主程式
	printf("難度（3: 3x3, 4: 4x4, 5: 5x5 以此類推(上限:25x25)）: ");  //詢問玩家欲挑戰的難度
    scanf("%d", &SIZE);

    if (SIZE < 3 || SIZE > MAX_SIZE) {
        printf("無效，請重新輸入。\n");
        return 1;
    }

    int row, col;
    char currentPlayer = 'X';

    initializeBoard();
    do {
        printBoard();
        printf("玩家 %c，請輸入行（1-%d）和列（1-%d）:", currentPlayer, SIZE, SIZE);
        scanf("%d %d", &row, &col);
        row--;
        col--;

        if (isValidMove(row, col)) {
            board[row][col] = currentPlayer;

            if (checkWin(currentPlayer)) {
                printBoard();
                printf("玩家 %c 贏了！\n", currentPlayer);
                break;
            } else if (isBoardFull()) {
                printBoard();
                printf("平局！\n");
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            printf("無效，請重新輸入。\n");
        }
    } while (1);
    return 0;
}