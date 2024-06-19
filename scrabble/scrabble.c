    #include<ctype.h>
    #include<cs50.h>
    #include<stdio.h>
    #include<string.h>

    //points assigned to each letter of the alphabet
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int compute_score(string word);

    int main(void)
    {
        //prompt the user for two words
        string word1 = get_string("Player 1: ");
        string word2 = get_string("Player 2: ");

        //compute the score of each word
        int score1 = compute_score(word1);
        int score2 = compute_score(word2);

    }
    int compute_score(string word);
    {
        //keep track of score
        int score = 0

        //compute score for each character
        for(int i = 0, length = strlen(word); i < length; i++)
        {
            if(isupper(word[i]))
            {
                score = POINTS[]
            }

}
