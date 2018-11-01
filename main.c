#include <stdio.h>
#include <stdlib.h>

char options[] = {'X', 'O'};
int x_win = 0, o_win = 0, draw = 0;

int win(char board[3][3])
{
    int i;
	for (i = 0; i < 3; i++) {
		if (board[i][0] != '\0' && board[i][0] == board[i][1] && board[i][2] == board[i][1]) {
			return 1;
		}
		if (board[0][i] != '\0' && board[0][i] == board[1][i] && board[2][i] == board[1][i]) {
			return 1;
		}
	}

	if (board[0][0] != '\0' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		return 1;
	}

	if (board[0][2] != '\0' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		return 1;
	}

	return 0;
}

int move(char board[3][3], int turn, int chances)
{
	if (win(board)) {
		if(turn == 0) {
			o_win++;
		} else {
			x_win++;
		}
		return 1;
	}

	if (chances == 9) {
		draw++;
		return 1;
	}

	int ans = 0;
	int i;
	int j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (board[i][j] == '\0') {
				board[i][j] = options[turn];
				ans += move(board, 1 - turn, chances + 1);
				board[i][j] = '\0';
			}
		}
	}

	return ans;
}

int main() {
	char board[3][3] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};

	int games_played = move(board, 0, 0);

	printf("Total games played: %d\n", games_played);
	printf("X wins: %d\n", x_win);
	printf("O wins: %d\n", o_win);
	printf("Draw: %d\n\n", draw);



	return 0;
}
