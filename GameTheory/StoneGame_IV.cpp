/**
 * @file StoneGame_IV.cpp
 * @brief Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.
 */

class Solution {
public:
    
    bool winnerSquareGame(int n) {
        bool *dp = new bool[n+1];
        for(int i=0;i<=n;i++)dp[i]=false;
        for(int i=0;i<=n;i++){
            if(!dp[i]) {
                for(int k=1;(i+k*k)<=n;k++){
                    dp[i+k*k]=true;
                }
            }
        }
        
        return dp[n];
    }
};