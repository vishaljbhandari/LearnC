#include <stdio.h>

void structure_1() {
	struct pixel {
		int horz;
		int vert;
		char color;
	};
	struct pixel center;

	center.horz = 320;
	center.vert = 240;
	center.color = 'r';

	printf("The pixel at %d,%d is colored ", center.horz, center.vert);
	switch (center.color) {
	case 'r':
		puts("red");
		break;
	case 'g':
		puts("green");
		break;
	case 'b':
		puts("blue");
		break;
	default:
		puts("Invalid");
	}
}

void structure_2() {
	struct pixel {
		int horz;
		int vert;
		char color;
	} center;

	center.horz = 320;
	center.vert = 240;
	center.color = 'r';

	printf("The pixel at %d,%d is colored ", center.horz, center.vert);
	switch (center.color) {
	case 'r':
		puts("red");
		break;
	case 'g':
		puts("green");
		break;
	case 'b':
		puts("blue");
		break;
	default:
		puts("Invalid");
	}
}

void structure_objects() {
	struct pixel {
		int horz;
		int vert;
		char color;
	} top, center, bottom;

	top.horz = 320;
	top.vert = 0;
	top.color = 'r';
	center.horz = 320;
	center.vert = 240;
	center.color = 'g';
	bottom.horz = 320;
	bottom.vert = 480;
	bottom.color = 'b';
}

void structure_initialize() {
	struct pixel {
		int horz;
		int vert;
		char color;
	} center = { 320, 240, 'r' };

	printf("The pixel at %d,%d is colored ", center.horz, center.vert);
	switch (center.color) {
	case 'r':
		puts("red");
		break;
	case 'g':
		puts("green");
		break;
	case 'b':
		puts("blue");
		break;
	default:
		puts("Invalid");
	}
}

void nested_struct() {
	struct date {
		int month;
		int day;
		int year;
	};
	struct person {
		struct date birthday;
		char name[32];
	};
	struct person president;

	president.birthday.month = 2;
	president.birthday.day = 22;
	president.birthday.year = 1732;
	strcpy(president.name, "George Washington");

	printf("%s was born on %d/%d/%d\n", president.name,
			president.birthday.month, president.birthday.day,
			president.birthday.year);
}

void nested_struct_as_member() {
	struct date {
		int month;
		int day;
		int year;
	};
	struct person {
		struct date birthday;
		struct date died;
		char name[32];
	};
	struct person president;

	president.birthday.month = 2;
	president.birthday.day = 22;
	president.birthday.year = 1732;
	president.died.month = 12;
	president.died.day = 14;
	president.died.year = 1799;
	strcpy(president.name, "George Washington");

	printf("%s was born on %d/%d/%d and died on %d/%d/%d\n", president.name,
			president.birthday.month, president.birthday.day,
			president.birthday.year, president.died.month, president.died.day,
			president.died.year);
}

void nested_struct_as_member_initialize() {
	struct date {
		int month;
		int day;
		int year;
	};
	struct person {
		struct date birthday;
		struct date died;
		char name[32];
	} president = { { 2, 22, 1732 }, { 12, 14, 1799 }, "George Washington" };

	printf("%s was born on %d/%d/%d and died on %d/%d/%d\n", president.name,
			president.birthday.month, president.birthday.day,
			president.birthday.year, president.died.month, president.died.day,
			president.died.year);
}

void struct_array_1() {
	struct pixel {
		int horz;
		int vert;
		char color;
	};
	struct pixel box[4];
	int x;

	box[0].horz = 100;
	box[0].vert = 50;
	box[0].color = 'r';
	box[1].horz = 200;
	box[1].vert = 50;
	box[1].color = 'r';
	box[2].horz = 100;
	box[2].vert = 100;
	box[2].color = 'r';
	box[3].horz = 200;
	box[3].vert = 100;
	box[3].color = 'r';

	for (x = 0; x < 4; x++) {
		printf("Pixel %d: %d, %d =  %c\n", x + 1, box[x].horz, box[x].vert,
				box[x].color);
	}
}

void struct_array_2() {
	struct pixel {
		int horz;
		int vert;
		char color;
	} box[4];
	int x;

	box[0].horz = 100;
	box[0].vert = 50;
	box[0].color = 'r';
	box[1].horz = 200;
	box[1].vert = 50;
	box[1].color = 'r';
	box[2].horz = 100;
	box[2].vert = 100;
	box[2].color = 'r';
	box[3].horz = 200;
	box[3].vert = 100;
	box[3].color = 'r';

	for (x = 0; x < 4; x++) {
		printf("Pixel %d: %d, %d =  %c\n", x + 1, box[x].horz, box[x].vert,
				box[x].color);
	}
}

void struct_array_initialize() {
	struct pixel {
		int horz;
		int vert;
		char color;
	} box[4] = { { 100, 50, 'r' }, { 200, 50, 'r' }, { 100, 100, 'r' }, { 200,
			100, 'r' } };
	int x;

	for (x = 0; x < 4; x++) {
		printf("Pixel %d: %d, %d =  %c\n", x + 1, box[x].horz, box[x].vert,
				box[x].color);
	}
}

void structure_use() {
	struct bank {
		int account;
		float balance;
	};
}

void struct_initialize() {
	struct bank {
		int account;
		float balance;
	};
	struct bank checking;

	checking.account = 1234;
	checking.balance = 567.89;

	printf("Checking account %d has a balance of %f\n", checking.account,
			checking.balance);
}

void structure_variable() {
	struct bank {
		int account;
		float balance;
	};
	struct bank checking, savings;

	checking.account = 1234;
	checking.balance = 567.89;
	savings.account = 9876;
	savings.balance = 543.21;

	printf("Checking account %d has a balance of %f\n", checking.account,
			checking.balance);
	printf("Savings account %d has a balance of %f\n", savings.account,
			savings.balance);
}

void structure_inline_initialize() {
	struct person {
		char name[32];
		int age;
	};
	struct person president = { "George Washington", 67 };

	printf("%s was %d years old\n", president.name, president.age);
}

void nested_structure() {
	struct date {
		int year;
		int month;
		int day;
	};
	struct person {
		char name[32];
		struct date birthday;
	};
	struct person friend;

	strcpy(friend.name, "George Washington");
	friend.birthday.year = 1732;
	friend.birthday.month = 2;
	friend.birthday.day = 22;

	printf("My friend %s was born on %d/%d/%d\n", friend.name,
			friend.birthday.month, friend.birthday.day, friend.birthday.year);
}

struct marks {
	int sub1;
	int sub2;
	int sub3;
	int total;
};

struct class {
	int number;
	char name[20];
	float marks;
};

void struct_compare() {
	int x;
	struct class student1 = { 222, "Reddy", 67.00 };
	struct class student2;

	student2 = student1;

	x = ((student2.number == student1.number)
			&& (student2.marks == student1.marks)) ? 1 : 0;

	if (x == 1) {
		printf("\nstudent1 and student2 are same\n\n");
		printf("%d %s %f\n", student2.number, student2.name, student2.marks);
	} else
		printf("\nstudent1 and student2 are different\n\n");
}

void array_of_structure() {
	int i;
	struct marks student[3] = { { 45, 67, 81, 0 }, { 75, 53, 69, 0 }, { 57, 36,
			71, 0 } };
	struct marks total = { 0, 0, 0, 0 };
	for (i = 0; i <= 2; i++) {
		student[i].total = student[i].sub1 + student[i].sub2 + student[i].sub3;
		total.sub1 = total.sub1 + student[i].sub1;
		total.sub2 = total.sub2 + student[i].sub2;
		total.sub3 = total.sub3 + student[i].sub3;
		total.total = total.total + student[i].total;
	}
	printf("STUDENT        TOTAL\n");
	for (i = 0; i <= 2; i++)
		printf("Student[%d]      %d\n", i + 1, student[i].total);
	printf("\nSUBJECT        TOTAL\n");
	printf("%s    %d\n%s    %d\n%s    %d\n", "Subject 1   ", total.sub1,
			"Subject 2   ", total.sub2, "Subject 3   ", total.sub3);
	printf("\nGrand Total =   %d\n", total.total);
	getch();
}

void array_As_structure() {
	struct marks {
		int sub[3];
		int total;
	};
	struct marks student[3] = { 45, 67, 81, 0, 75, 53, 69, 0, 57, 36, 71, 0 };
	struct marks total = { 0, 0, 0, 0 };
	int i, j;

	for (i = 0; i <= 2; i++) {
		for (j = 0; j <= 2; j++) {
			student[i].total += student[i].sub[j];
			total.sub[j] += student[i].sub[j];
		}
		total.total += student[i].total;
	}
	printf("STUDENT         TOTAL\n");
	for (i = 0; i <= 2; i++)
		printf("Student[%d]      %d\n", i + 1, student[i].total);

	printf("\nSUBJECT         TOTAL\n");
	for (j = 0; j <= 2; j++)
		printf("Subject-%d       %d\n", j + 1, total.sub[j]);

	printf("\nGrand Total  =  %d\n", total.total);
}

struct stores {
	char name[20];
	float price;
	int quantity;
};
struct stores update(struct stores product, float p, int q);
float mul(struct stores stock);
void structures() {
	float p_increment, value;
	int q_increment;

	struct stores item = { "XYZ", 25.75, 12 };

	printf("\nInput increment values:");
	printf("   price increment and quantity increment\n");
	scanf("%f %d", &p_increment, &q_increment);

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
	item = update(item, p_increment, q_increment);
	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
	printf("Updated values of item\n\n");
	printf("Name      : %s\n", item.name);
	printf("Price     : %f\n", item.price);
	printf("Quantity  : %d\n", item.quantity);

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
	value = mul(item);
	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
	printf("\nValue of the item  =  %f\n", value);
	getch();
}
struct stores update(struct stores product, float p, int q) {
	product.price += p;
	product.quantity += q;
	return (product);
}
float mul(struct stores stock) {
	return (stock.price * stock.quantity);
}

#include <stdio.h>

void show_pixel(struct pixel p);

struct pixel {
	int horz;
	int vert;
	char color;
};

void show_pixel(struct pixel p) {
	printf("Pixel found at %d,%d, color = ", p.horz, p.vert);
	switch (p.color) {
	case 'r':
		puts("red");
		break;
	case 'g':
		puts("green");
		break;
	case 'b':
		puts("blue");
		break;
	default:
		puts("Invalid");
	}
}

char* show_color(char c) {
	switch (c) {
	case 'r':
		return ("red");
	case 'g':
		return ("green");
	case 'b':
		return ("blue");
	default:
		return ("Invalid");
	}
}

struct date {
	int month;
	int day;
	int year;
};
struct person {
	char name[32];
	struct date tookoffice;
};

void show(struct person p[]) {
	int x;

	puts("Presidents:");
	for (x = 0; x < 4; x++) {
		printf("President %s took office on %d/%d/%d\n", p[x].name,
				p[x].tookoffice.month, p[x].tookoffice.day,
				p[x].tookoffice.year);
	}
}

int main() {

	struct pixel center;

	center.horz = 320;
	center.vert = 240;
	center.color = 'r';

	show_pixel(center);

	printf("The pixel at %d,%d is colored %s\n", center.horz, center.vert,
			show_color(center.color));

	struct person presidents[4] = { { "George Washington", { 4, 30, 1789 } }, {
			"Thomas Jefferson", { 3, 4, 1801 } }, { "Abraham Lincoln", { 3, 4,
			1861 } }, { "Theodore Roosevelt", { 9, 14, 1901 } } };
	struct person temp;

	/* show them */
	show(presidents);
	/* swap 2 and 3 */
	printf("Swapping...");
	temp = presidents[1];
	presidents[1] = presidents[2];
	presidents[2] = temp;
	printf("done!\n");
	/* show again */
	show(presidents);

	structure_1();
	structure_2();
	structure_objects();
	structure_initialize();
	nested_struct();
	nested_struct_as_member();
	nested_struct_as_member_initialize();
	struct_array_1();
	struct_array_2();
	struct_array_initialize();

	structures();
	struct_compare();
	array_of_structure();
	array_As_structure();

	structure_use();
	struct_initialize();
	structure_variable();
	structure_inline_initialize();
	nested_structure();
	return 0;
}
