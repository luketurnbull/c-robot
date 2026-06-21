#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 10
#define SQUARE_SIZE 3

struct Coords {
	int x;
	int y;
};

void draw(struct Coords robot) {
	for (int y = 1; y < BOARD_SIZE + 1; y++) {
		for (int x = 1; x < BOARD_SIZE + 1; x++) {
			char *cell = x == robot.x && y == robot.y ? "[x]" : "[ ]";

			if (x == BOARD_SIZE) {
				printf("%s\n", cell);
			} else {
				printf("%s", cell);
			}
		}
	}
}

int main() {
	struct Coords target = {.x = 7, .y = 7};
	struct Coords robot = {.x = 5, .y = 5};

	while (robot.x != target.x || robot.y != target.y) {
		char direction[1024];
		printf("Enter a direction; u(p) r(ight) l(eft) d(own))\n");
		scanf("%1023s", direction);

		if (!strcmp(direction, "u")) {
			robot.y--;
		} else if (!strcmp(direction, "r")) {
			robot.x++;
		} else if (!strcmp(direction, "l")) {
			robot.x--;
		} else if (!strcmp(direction, "d")) {
			robot.y++;
		} else {
			printf("Invalid input, robot has not moved");
			break;
		}

		draw(robot);
	}

	return 0;
}
