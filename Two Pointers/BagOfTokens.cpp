// 948. Bag of Tokens
// You have an initial power of power, an initial score of 0, and a bag of tokens where tokens[i] is the value of the ith token (0-indexed).
// Your goal is to maximize your total score by potentially playing each token in one of two ways:
// -> If your current power is at least tokens[i], you may play the ith token face up, losing tokens[i] power and gaining 1 score.
// -> If your current score is at least 1, you may play the ith token face down, gaining tokens[i] power and losing 1 score.
// Each token may be played at most once and in any order. You do not have to play all the tokens.
// Return the largest possible score you can achieve after playing any number of tokens.

//APPROACH :
// The idea is to follow a greedy approach.
// First of all sort the tokens array.
// Here it is mentioned that we have two options:
// 1. Either lose power and gain score
// 2. Lose points and gain power.
// And our aim is to get max score possible.
// For any amount of power we lose we will attain the same score that is one.
// Here we think greedily and lose the minimum power possible and gain the score.
// And if the power is less than the minimum power, in that case we lose one point for attain the maximum power possible again greedily.
// In that way we figure out the max score that can attained by running a while loop and traversing the entire tokens vector.

int maxScore(vector<int> &tokens, int power){
    int n = tokens.size();
    int left = 0, right = n-1;
    int score = 0;
    sort(tokens.begin(), tokens.end());
    while(left <= right && (score || power >= tokens[left])){
        if(power >= tokens[left]){
            power -= tokens[left];
            score++;
            left++;
        }
        else if(left != right){
            power += tokens[right];
            score--;
            right--;
        }
        else break;
    }
    return score;
}

// T.C = O(N)



