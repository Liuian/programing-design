#include<math.h>
#include<stdio.h>


int main(){
	float bmi, height, birth, weight, age;
	char *phys, *mili;

	scanf("%f", &birth);
	scanf("%f", &height);
	scanf("%f", &weight);

	age = 2021 - birth;
	bmi = weight / pow((height/100), 2);

	if(age < 19 || age > 36){
		phys = "Not a Draftee (age < 19 or age > 36 years old)";
		mili = "No need to perform Military Service";
	}
	else{
		if(bmi >= 17 && bmi <= 31){
			phys = "Physical Status of Regular Service Draftees";
			if(birth <= 1993){
				mili = "1 year of Regular Service";
			}
			if(birth >= 1994){
				mili = "4 months of Regular Service";
			}
		}
		else if((bmi >= 16.5 && bmi <17) || (bmi > 31 && bmi <= 31.5)){
			phys = "Physical Status of Substitute Service Draftees";
			if(birth <= 1993){
				mili = "Substitute Services";
			}
			if(birth >= 1994){
				mili = "Replacement Service";
			}
		}
		else{
			phys = "Physical Status of Military Service Exemption";
			mili = "Exemption from Military Service";
		}
	}

	printf("Age = %.0f\n", age);
	printf("Height = %.0fcm\n", height);
	printf("Weight = %.0fKg\n", weight);
	printf("BMI = %.1f\n", bmi);
	printf("%s\n", phys);
	printf("%s", mili);
	

	return 0;
}
/*
	if(17 <= bmi && bmi <=31) {
		phys = "Physical Status of Regular Service Draftees";
		if(age <= 36 && age >= 27) mili = "1 year of Regular Service";
		else if(age < 27 && age >= 19) mili = "4 months of Regular Service";
		else{
			phys ="No need to perform Military Service";
			mili = NULL;
		}
	}
	 if((16.5 <= bmi && bmi < 17) || (31 < bmi && bmi <= 31.5)) {
		phys = "Physical Status of Substitute Service Draftees";
		if(age <= 36 && age >= 27) mili = "Substitute Services";
		else if(age < 27 && age >= 19) mili = "Replacement Service";
	//	else phys = "No need to perform Military Service";
		else{
			phys ="No need to perform Military Service";
			mili = NULL;
		}
	}
	if(bmi < 16.5 || bmi > 31.5) {
		phys = "Physical Status of Military Service Exemption";
		if(age >= 19 && age <= 36) mili = "Exemption from Military Service";
	//	else phys = "No need to perform Military Service";
		else{
			phys ="No need to perform Military Service";
			mili = NULL;
		}
	}*/
