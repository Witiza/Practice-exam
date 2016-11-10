#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
	MidTerm Examination for UPC's Computer Programming 1 - 2015 -
	Time: 2 hours
	Submission: When you are finish upload the result in a zip named "lastname_name.zip" to Agora website
	Special rules: You are free to use your notes and the C book
	The compiled solution is located in the same folder "solution.exe"
*/

int main()
{
	// ----------------------------------------------------------------------------------
	// Exercise 1 (2 points): Given a character of a single digit, convert it to integer
	// you cannot use scanf or atoi.
	// ----------------------------------------------------------------------------------
	char my_char = 0;
	int my_number = 0;

	printf("\n1. Insert a 1 digit number to convert to int: ");
	scanf_s("%c", &my_char, 1);

	my_number = my_char - 48;

	// <<< --------- INSERT YOUR CODE HERE FOR EXERCISE 1

	printf("The number you inserted is %d", my_number);

	// ----------------------------------------------------------------------------------
	// Exercise 2 (2 points): Given a number < 100, find out if it is a prime number.
	// prime numbers can only be divided by 1 and by themselves without any leftover.
	// ----------------------------------------------------------------------------------
	int prime_check = 0;

	printf("\n2. Insert a number to check if it is a prime number: ");
	scanf_s("%d", &prime_check);

	// <<< --------- INSERT YOUR CODE HERE FOR EXERCISE 2
	int counter = 2;
	int boolean_prime = 0;
	if (prime_check != 1)
	{
		while (counter <= 100)
		{
			if (prime_check % counter == 0)
			{
				boolean_prime++;
			}
			counter++;
		}
		if (boolean_prime == 1)
		{
			printf("%d is prime", prime_check);
		}
		else
		{
			printf("%d is not prime", prime_check);
		}
	}
	else
	{
		printf("%d is prime", prime_check);
	}



	// ----------------------------------------------------------------------------------
	// Exercise 3 (4 points): We have a Dragon with 100 hit points. Write an attack
	// calculator that asks for amount of damage and type (can be "f" for fire or
	// "c" for cold). A valid input would be "34 f" which means fire damage of 34.
	// Taking in account that the fire elemental has 21% resistance to fire but
	// a vulnerability of 38% to cold damage, calculate the final hit points.
	// The program must continue until the fire elemental dies (<= 0 hit points).
	// The fire elemental can never have negative hit points.
	// ----------------------------------------------------------------------------------

	// <<< --------- INSERT YOUR CODE HERE FOR EXERCISE 3
	int damage;
	char type;
	int hp = 100;

	while (hp > 0)
	{
		printf("\n3. Enter damage to the Dragon: ");
		scanf_s("%d %c", &damage, &type, 1);
		if (type == 'f')
		{
			damage = damage*0.79;
			hp = hp - damage;
			if (hp < 0)
			{
				hp = 0;
				printf("You have dealt %d fire damage to the dragon. \nThe dragon has %d hp left, you have defeated the dragon", damage, hp);
			}
			else if (hp > 0)
			{
				printf("You have dealt %d fire damage to the dragon. \nThe dragon has %d hp left", damage, hp);
			}
			damage = 0;
		}
		else if (type == 'c')
		{
			damage = damage*1.38;
			hp = hp - damage;
			if (hp < 0)
			{
				hp = 0;
				printf("You have dealt %d ice damage to the dragon. \nThe dragon has %d hp left, you have defeated the dragon", damage, hp);
			}
			else if (hp > 0)
			{
				printf("You have dealt %d ice damage to the dragon. \nThe dragon has %d hp left", damage, hp);
			}
			damage = 0;
		}
	}
	



	// ----------------------------------------------------------------------------------
	// Exercise 4 (2 points): Ask the use the amount of fireballs that your mage should throw
	// taking in account that the mage has a 85% probability of hit and 15% of crit
	// probability, calculate the amount of times it hits, misses and crits.
	// ----------------------------------------------------------------------------------
	int amount_fireballs;
	
	printf("\n4. Enter damage the amount of fireballs to cast: ");
	scanf_s("%d", &amount_fireballs);

	srand(time(NULL));
	// <<< --------- INSERT YOUR CODE HERE FOR EXERCISE 4
	// rand() % 101 // should give a random number from 1 to 100
	int hits = 0;
	int misses = 0;
	int demcrits = 0;
	for (int i = 1; i <= amount_fireballs; i++)
	{
		int hit_chance = rand() % 101;
			if (hit_chance <= 85)
			{
				hits++;
				int crit_chance = rand() % 101;
				if (crit_chance <= 15)
				{
					demcrits++;
				}
			}
			else if (hit_chance > 85)
			{
				misses++;
			}
	}
	printf("The mage has thrown %d fireballs. \n Hits: %d \n Misses: %d \n Crits: %d", amount_fireballs, hits, misses, demcrits);

	// ----------------------------------------------------------------------------------
	getchar();
	getchar();
	return 0;
}