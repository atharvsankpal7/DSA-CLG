#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct score_node
{
    int score;
    struct score_node *next;
};

struct student_node
{
    char name[30];
    struct score_node *score_head;
    struct student_node *next;
};

int main()
{
    FILE *fp;
    struct student_node *student_head, *p;
    struct score_node *score_p;
    int score, count, sum;
    float average;

    student_head = NULL;
    fp = fopen("students1.txt", "r");
    if (fp == NULL)
    {
        printf("File does not exist\n");

        return 0;
    }

    while (!feof(fp))
    {
        p = (struct student_node *)malloc(sizeof(struct student_node));
        fscanf(fp, "%s", p->name);
        p->score_head = NULL;
        p->next = student_head;
        student_head = p;
    }

    fclose(fp);

    p = student_head;
    while (p != NULL)
    {
        printf("Enter scores for %s: \n", p->name);
        count = 0;
        sum = 0;
        while (count < 4)
        {
            printf("Score %d: ", count + 1);
            scanf("%d", &score);
            score_p = (struct score_node *)malloc(sizeof(struct score_node));
            score_p->score = score;
            score_p->next = p->score_head;
            p->score_head = score_p;
            sum += score;
            count++;
        }
        average = (float)sum / count;
        printf("%s's scores: ", p->name);
        score_p = p->score_head;
        while (score_p != NULL)
        {
            printf("%d ", score_p->score);
            score_p = score_p->next;
        }
        printf("\nTotal score: %d\nAverage score: %.2f\n\n", sum, average);
        p = p->next;
    }

    return 0;
}
