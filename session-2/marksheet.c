#include<stdio.h>
main(){
	float marks;
	printf("enter your marks");
	scanf("%f",&marks);
//	printf("marks is := %.2f",marks);
	 if (marks < 0 || marks > 100) {
        printf("Error: Percentage must be between 0 and 100.\n");
    }
    else if(marks>=90){
		printf("Grade= A-Good work! Keep pushing");
	}
	else if(marks>=75){
		printf("Grade= B-Good work! Keep pushing");x
	}
	else if(marks>=60){
		printf("Grade= C-Nice effort! You can do even better.");
	}
	else if(marks>=45){
		printf("Grade= D-Keep practicing! You can improve");
	}
	else{
		printf("Grade = F — Don't give up! Keep learning and try again");
	}
}
