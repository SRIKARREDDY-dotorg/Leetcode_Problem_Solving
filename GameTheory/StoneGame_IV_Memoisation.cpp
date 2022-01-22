/**
 * @file StoneGame_IV.cpp
 * @brief Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.
 */

class Solution {
public:
    bool winnerWinner_ChickenDinner(unordered_map<int,bool> &cache, int n) {
        if(cache.find(n)!=cache.end()) return cache[n];
        int square_root = (int)sqrt(n);
        
        for(int i=1; i<=square_root; i++) {
            
            if(!winnerWinner_ChickenDinner(cache, n-(i*i))) {
                cache[n]=true;
                return true;
            }
            
        }
        cache[n]=false;
        return false;
    }
    bool winnerSquareGame(int n) {
        unordered_map<int,bool> cache;
        cache[0]=false;
        return winnerWinner_ChickenDinner(cache, n);
    }
};