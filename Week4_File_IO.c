/*
 * Week_4 This program opens and reads a file of integer pairs into an array.
 * Adds, multiplies, subtracts and divides rationals and calculates the average of all
 * the rationals in the file.
 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
typedef struct rationalNumber
{
	int numerator;
	int denominator;

}rationalNumber;

rationalNumber multiplyRationals(rationalNumber p1, rationalNumber p2);

void getNumOfPairs(FILE * ifp, int * numOfpairs)
{
	if(ifp == NULL)
	{
		printf("Error opening file\n");
		exit(1);
	}
		if(fscanf(ifp, "%d", numOfpairs) != EOF)

		   printf("Number of Pairs: %d\n", *numOfpairs);
}
void readPairs(FILE * ifp, rationalNumber * pairs, int size)
{
	int i=0, j=0;

	while (fscanf(ifp, "%d %d", &pairs[i].numerator, &pairs[i].denominator) !=EOF && i<size)
		i++;

		for(j=0; j<size; j++ )
			printf("%d %d \n", pairs[j].numerator, pairs[j].denominator);
}
rationalNumber getAbsValue(rationalNumber rN, rationalNumber * r)
{
	r->numerator = 1;
	r->denominator = 1;
	if(rN.numerator < 0) {
		r->numerator = -1;
		rN.numerator = - rN.numerator;
	}
	if(rN.denominator < 0) {
		r->denominator = -1;
		rN.denominator = - rN.denominator;
	}

	return rN;
}

rationalNumber simplify(rationalNumber rN)
{
	rationalNumber r;
	rationalNumber aRN = getAbsValue(rN, &r);

	int i, least;

	if(aRN.numerator<aRN.denominator)
		least = aRN.numerator;
	else
		least = aRN.denominator;

	if(aRN.numerator > 0 )
	{
		if(aRN.numerator % aRN.denominator == 0)
		{
			aRN.numerator = aRN.numerator/aRN.denominator;
			aRN.denominator = aRN.denominator/aRN.denominator;

		}else if(aRN.denominator % aRN.numerator ==0)
		{
			aRN.numerator = aRN.numerator/aRN.numerator;
			aRN.denominator = aRN.denominator/aRN.numerator;
		}else
		{
			for (i=2; i<least;)
				if(aRN.numerator % i == 0 && aRN.denominator % i == 0)
				{
					aRN.numerator = aRN.numerator/i;
					aRN.denominator = aRN.denominator/i;
				}else i++;
		}
	}
	//call multiply to get back a correct sign
	return multiplyRationals(aRN, r);
}

rationalNumber addRationals(rationalNumber p1, rationalNumber p2)
{
	rationalNumber rN ;

	if(p1.denominator == p2.denominator)
	{
		rN.numerator = p1.numerator + p2.numerator;
		rN.denominator = p1.denominator;
	}
	else{
		rN.numerator = p1.numerator * p2.denominator + p2.numerator * p1.denominator;
		rN.denominator = p1.denominator * p2.denominator;
	}

	rN = simplify(rN);

	return rN;
}
rationalNumber subtractRationals(rationalNumber p1, rationalNumber p2)
{
	p2.numerator = - p2.numerator;

	return addRationals( p1, p2);
}
rationalNumber multiplyRationals(rationalNumber p1, rationalNumber p2)
{
	rationalNumber rN;

	rN.numerator = p1.numerator * p2.numerator;
	rN.denominator = p1.denominator * p2.denominator;
	if(abs(p2.numerator)!=1 && abs(p2.denominator)!=1)
		rN = simplify(rN);
	return rN;
}
rationalNumber divideRationals(rationalNumber p1, rationalNumber p2)
{
	rationalNumber rN;
	rN.denominator = p2.numerator;
	rN.numerator = p2.denominator;
	return multiplyRationals(p1, rN);
}
rationalNumber findSum(rationalNumber p[], int size)
{
	rationalNumber sum = p[0];
	int i;
	for(i=1; i<size; i++)
		sum = addRationals(sum , p[i]);

	return sum;
}
int main()
{
	srand(time(NULL)); //set the starting value (seed) for rand() generating a sequence of pseudo-random integer values.
	rationalNumber intP, sum, average, numOfP;
	FILE *ifp;
	int numOfpairs=0;
	int rPair1, rPair2 ;

	ifp = fopen("intPairs.txt", "r");
	getNumOfPairs(ifp, &numOfpairs);
	//create an array of pairs
	rationalNumber pairs[numOfpairs];
	readPairs(ifp,pairs, numOfpairs);

	if(pairs[rPair1].denominator ==0 || pairs[rPair2].denominator==0)
		printf("Cannot divide by 0 \n");
	else
	{
		//pick random element from the array
		rPair1 = rand() % numOfpairs;
		rPair2 = rand() % numOfpairs;
		intP = addRationals(pairs[rPair1], pairs[rPair2]);
		printf("Add Rational numbers: \n %d/%d + %d/%d = %d/%d\n",pairs[rPair1].numerator, pairs[rPair1].denominator, pairs[rPair2].numerator, pairs[rPair2].denominator, intP.numerator, intP.denominator);
		rPair1 = rand() % numOfpairs;
		rPair2 = rand() % numOfpairs;
		intP =subtractRationals(pairs[rPair1], pairs[rPair2]);
		printf("Subtract Rational numbers: \n %d/%d - %d/%d = %d/%d\n",pairs[rPair1].numerator, pairs[rPair1].denominator, pairs[rPair2].numerator, pairs[rPair2].denominator, intP.numerator, intP.denominator);
		rPair1 = rand() % numOfpairs;
		rPair2 = rand() % numOfpairs;
		intP = multiplyRationals(pairs[rPair1], pairs[rPair2]);
		printf("Multiply Rational numbers: \n %d/%d * %d/%d = %d/%d\n",pairs[rPair1].numerator, pairs[rPair1].denominator, pairs[rPair2].numerator, pairs[rPair2].denominator, intP.numerator, intP.denominator);
		rPair1 = rand() % numOfpairs;
		rPair2 = rand() % numOfpairs;
		intP = divideRationals(pairs[rPair1], pairs[rPair2]);
		printf("Divide Rational numbers: \n %d/%d / %d/%d = %d/%d\n",pairs[rPair1].numerator, pairs[rPair1].denominator, pairs[rPair2].numerator, pairs[rPair2].denominator, intP.numerator, intP.denominator);

	}
	//to find average create a rational number using number of pairs
	numOfP.numerator = numOfpairs;
	numOfP.denominator = 1;

	sum = findSum(pairs, numOfpairs);
	printf("Sum of Rational numbers: %d/%d \n", sum.numerator, sum.denominator );
	average = divideRationals(sum,numOfP);
	printf("Average of Rational numbers: %d/%d \n", average.numerator, average.denominator);
	fclose(ifp);

	return 0;
}
