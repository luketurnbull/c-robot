#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 10
#define SQUARE_SIZE 3

struct Coords {
	int x;
	int y;
};

void draw(struct Coords robot, struct Coords target) {
	for (int y = 1; y < BOARD_SIZE + 1; y++) {
		for (int x = 1; x < BOARD_SIZE + 1; x++) {
			char *cell = "[ ]";

			// Check if target is this cell
			if (x == target.x && y == target.y) {
				cell = "[o]";
			}

			// Check if robot is this cell
			if (x == robot.x && y == robot.y) {
				cell = "[x]";
			}

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

	// Draw the initial grid
	draw(robot, target);

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

		draw(robot, target);
	}

	printf("You found the target!");
	return 0;
}
