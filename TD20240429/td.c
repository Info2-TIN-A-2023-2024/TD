#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // malloc
#include <string.h> // memcpy

typedef enum
{
	POINT2D = 0,
	COLOR = 1
} data_type;

typedef struct
{
	double x;
	double y;
} point2d;

typedef struct
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
} color;

typedef struct
{
	data_type type;
	size_t qty;
	uint8_t checksum;
} header;

typedef union
{
	point2d p;
	color c;
} data;

typedef struct
{
	header h;
	data d;
} packet;

void display_packet(const packet p)
{

	switch (p.h.type)
	{
	case COLOR:
		printf("%02X %02X %02X\n", p.d.c.r, p.d.c.g, p.d.c.b);
		break;
	case POINT2D:
		printf("%+6.3lf %+6.3lf\n", p.d.p.x, p.d.p.y);
		break;
	default:
		puts("unknown packet type.");
		break;
	}
}

void send(const packet p, char *buff)
{
	memcpy(buff, &p, sizeof(packet));
}

void receive(char *buffer, packet *p)
{
	memcpy(p, buffer, sizeof(packet));
}

int main(int argc, const char *argv[])
{
	packet p1;
	p1.h.type = COLOR;
	p1.h.qty = 1;
	p1.h.checksum = 0;
	p1.d.c.r = 0;
	p1.d.c.g = 255;
	p1.d.c.b = 255;
	display_packet(p1);

	packet p2;
	p2.h.type = POINT2D;
	p2.h.qty = 1;
	p2.h.checksum = 0;
	p2.d.p.x = 0.707;
	p2.d.p.y = 0.707;
	display_packet(p2);

	char *buffer = (char *)malloc(sizeof(packet));
	if (NULL == buffer)
	{
		puts("Error alloc buffer");
		return 1;
	}

	send(p1, buffer);

	packet prx;
	receive(buffer, &prx);
	display_packet(prx);
	return 0;
}