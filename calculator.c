#include <stdio.h>
#include <stdlib.h>

// 윤성민
int main() {
	// 변수 선언 및 초기화
	int selection = 0;

	// 소개
	printf("계산기 프로그램\n");
	printf("강성원 유지헌 윤성민 이효근\n");
	printf("\n");

	while (1)
	{
		// 원하는 것 선택
		printf("1. 사칙연산 2. 원리합계/시그마 3. 미분\n");
		printf("원하는 것을 선택해주세요(번호): ");
		//scanf_s("%d", &selection);
		scanf("%d", &selection);

		// 원하는 것에 따른 함수 호출
		if (selection == 1) {
			// General GCC
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");

			// Excute Function
			basicCalulation();
			break;
		}
		else if (selection == 2) {
			// General GCC
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");

			// Excute Function
			sigma();
			break;
		}
		else if (selection == 3) {
			// General GCC
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");

			// Excute Function
			differentiation();
			break;
		}
		else {
			printf("다시 입력해주세요\n");
		}
	}
	return 0;
}

// 유지헌
int basicCalulation() {
	printf("사칙연산\n");
	int a, op, b;
	int result;

	printf("수식을 입력하시오: \n ex) < 2 + 5 > ");
	scanf("%d %c %d", &a, &op, &b);

	if (op == '+')
		result = a + b;
	else if (op == '-')
		result = a - b;
	else if (op == '*')
		result = a * b;
	else if (op == '/')
		result = a / b;
	else
		printf("지원되지 않는 연산자 입니다.");

	printf("%d %c %d = %d", a, op, b, result);

	return 0;
}

// 이효근
int power(int x, int y)
{
	if (y == 0) return 1;
	return x * power(x, y - 1);
}
int sigma() {
	int selection;
	int a, n, d, Sn; // 등차수열
	int A, R, N, NN, NNN, SN, Double; // 등비수열

	printf("1. 등차수열의 합 계산 2. 등비수열의 합 계산 3. n^2의 합 계산 4. n^3의 합 계산\n");
	printf("원하는 것을 선택해주세요(번호): ");
	scanf("%d", &selection);
	if (selection == 1) {
		printf("등차수열\n");
		printf("첫번째 항을 입력하세요: ");
		scanf("%d", &a);

		printf("공차를 입력하세요: ");
		scanf("%d", &d);

		printf("몇번째 항까지 계산 하시겠습니까: ");
		scanf("%d", &n);

		Sn = n * (2 * a + (n - 1) * d) / 2;
		printf("%d항까지의 합은 %d 입니다.\n\n\n", n, Sn);
	}
	else if (selection == 2){
		printf("등비수열\n");

		printf("첫번째 항을 입력하세요: ");
		scanf("%d", &A);

		printf("공비를 입력하세요: ");
		scanf("%d", &R);

		printf("몇번째 항까지 계산하시겠습니까: ");
		scanf("%d", &N);

		NN = N - 1;
		NNN;
		NNN = power(R, N);
		Double = power(R, NN);
		
		SN = A * (NNN - 1) / (R - 1);
		printf("%d항까지의 합은 %d 입니다.", N, SN);
	}
	else if (selection == 3){
		int n, k;

		printf("n^2 + n+1^2 ...계산하기\n");
		printf("몇번째 항까지 계산하시겠습니까: ");
		scanf("%d", &n);
		k = n * (n + 1) * ((2 * n) + 1) / 6;
		
		printf("%d항까지의 합은 %d 입니다.", n, k);
	}

	else if (selection == 4) {
		int n, k;
		printf("n^3 + n+1^3 ...계산하기\n");
		printf("몇번째 항까지 계산하시겠습니까: ");
		scanf("%d", &n);
		k = n * (n + 1) / 2;
		k = power(k, 2);
		printf("%d항까지의 합은 %d 입니다.", n, k);
	}
	return 0;
}

// 강성원
int differentiation() {
	int p = 0;
	char equation[500];
	char result[500];
	int s_number = 0, e_number = 0, s_expo = 0, e_expo = 0;
	int number = 0, expo = 0, check = 0, index = 0;

	printf("방정식을 입력하세요! (문자 옆에 숫자는 제곱, 문자의 대소문자는 구분X)\n");
	scanf("%s", equation);

	while (equation[p] != NULL) {
		if (equation[p] >= '0' && equation[p] <= '9') { //숫자를 발견 하였을 경우
			switch (check) {//제곱인 경우와 개수인 경우를 따로 본다.
			case 1:
				expo = (equation[p] - '0') + (expo * 10);
				break;
			default:
				number = (equation[p] - '0') + (number * 10);
				break;
			}
		}
		if (equation[p] >= 'A' && equation[p] <= 'Z' || equation[p] >= 'a' && equation[p] <= 'z') {//만약 문자를 만났을 경우
			check = 1;
			e_number = p - 1;
			s_expo = p + 1;
		}
		if (equation[p + 1] == '+' || equation[p + 1] == '-' || equation[p + 1] == NULL && check == 1) {//연산자를 만났을 경우
			if (expo == 0) expo = 1;
			if (number == 0) number = 1;
			e_expo = p;
			number *= expo;
			expo -= 1;
			check = 0;

			int point = index;

			int tmp = number;
			while (tmp != 0) {
				tmp /= 10;
				index++;
			}

			for (int i = index - 1; i >= point; i--) {
				result[i] = (number % 10) + '0';
				number /= 10;
			}

			if (expo == 0) return;

			result[index++] = equation[e_number + 1];
			point = index;

			tmp = expo;
			while (tmp != 0) {
				tmp /= 10;
				index++;
			}

			for (int i = index - 1; i >= point; i--) {
				if (expo == 1) {
					index--;
					break;
				}
				result[i] = (expo % 10) + '0';
				expo /= 10;
			}
			result[index++] = equation[e_expo + 1];

			expo = 0;
			number = 0;
			s_number = p + 1;
		}
		p++;
	}
	printf("%s", result);
	return 0;
}
