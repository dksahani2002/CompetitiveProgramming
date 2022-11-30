// #include <bits/stdc++.h>
// using namespace std;

// int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
// {	Sx--;Sy--;Fx--;Fy--;
// 	// Complete the function
//     int n=N;
//     int board[n][n];
//     memset(board,-1,sizeof(board));
//     int dx[]={2,-2,2,-2,1,-1,1,-1};
//     int dy[]={1,1,-1,-1,2,2,-2,-2};
//     queue<pair<int,int>>q;
//     q.push({Sx,Sy});
//  	board[Sx][Sy]=0;
//     while(!q.empty()){
//         int x=q.front().first;
//         int y=q.front().second;
//         q.pop();
//         for(int k=0;k<8;k++){
//             int i=x+dx[k];
//             int j=y+dy[k];
//             if(i>=0 && i<n && j>=0 && j<n && board[i][j]==-1){
// 				if(i==Fx && j==Fy){ 
//                     return 1+board[x][y];
//                 } 
//                 q.push({i,j});
//                 board[i][j]=1+board[x][y];
//             }
//         }
        
//     }
//  return board[Fx][Fy];
// }

// int main()
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	int test_case;
// 	cin >> test_case;

// 	while (test_case--)
// 	{
// 		int N, Sx, Sy, Fx, Fy;
// 		cin >> N >> Sx >> Sy >> Fx >> Fy;

// 		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
// 	}
// }
#include <bits/stdc++.h>
using namespace std;

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{	Sx--;Sy--;Fx--;Fy--;
	// Complete the function
    int n=N;
    int board[n][n] ;
 memset(board,-1,sizeof(board));
    int dx[]={2,-2,2,-2,1,-1,1,-1};
    int dy[]={1,1,-1,-1,2,2,-2,-2};
    queue<pair<int,int>>q;
    q.push({Sx,Sy});
 	board[Sx][Sy]=0;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int k=0;k<8;k++){
            int i=x+dx[k];
            int j=y+dy[k];
            if(i>=0 && i<n && j>=0 && j<n && board[i][j]==-1){
				if(i==Fx && j==Fy){ 
                    return 1+board[x][y];
                } 
                q.push({i,j});
                board[i][j]=1+board[x][y];
            }
        }
        
    }
 return board[Fx][Fy];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
}