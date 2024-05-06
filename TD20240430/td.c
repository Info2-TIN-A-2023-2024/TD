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
	data *d; // pointer to dynamic area
} packet;

void display_packet(const packet p)
{
	size_t index = 0;
	for (index = 0; index < p.h.qty; index++)
	{
		switch (p.h.type)
		{
		case COLOR:
			printf("%02X %02X %02X\n", p.d[index].c.r, p.d[index].c.g, p.d[index].c.b);
			break;
		case POINT2D:
			printf("%+6.3lf %+6.3lf\n", p.d[index].p.x, p.d[index].p.y);
			break;
		default:
			puts("unknown packet type.");
			break;
		}
	}
}

void send(const packet p, char *buff)
{
	uint8_t *ptr = (uint8_t *)p.d;
	uint8_t cks = 0;
	for (size_t index = 0; index < p.h.qty * sizeof(data);index++) {
		cks += *(ptr+index);
	}
	printf("send: computed cks=%d\n", cks);
	memcpy(buff, &(p.h), sizeof(header));
	((packet *)buff)->h.checksum = cks;
	memcpy(buff + sizeof(header), p.d, p.h.qty * sizeof(data));
	
}

int receive(char *buff, packet *p)
{

	memcpy(p, buff, sizeof(header));
	p->d = (data *)malloc(sizeof(data) * p->h.qty);
	if (NULL == p->d)
	{
		printf("receive:: Error while allocating data.\n");
		return 1;
	}
	uint8_t *ptr = (uint8_t *)buff + sizeof(header);
	uint8_t cks = 0;
	for (size_t index = 0; index < p->h.qty * sizeof(data);index++) {
		cks += *(ptr+index);
	}
	printf("receive: computed cks=%d, received cks=%d\n", cks, 	((packet *)buff)->h.checksum );

	memcpy(p->d, buff + sizeof(header), p->h.qty * sizeof(data));
	return 0;
}

int main(int argc, const char *argv[])
{
	packet p1;
	packet p2;
	p1.h.type = COLOR;
	p1.h.qty = 3;
	p1.h.checksum = 0;
	color red = {.r = 255, .g = 0, .b = 0};
	color cyan = {.r = 0, .g = 255, .b = 255};
	color magenta = {.r = 255, .g = 0, .b = 255};

	p1.d = (data *)malloc(sizeof(data) * p1.h.qty);
	if (NULL == p1.d)
	{
		printf("Error while allocating data.\n");
		return 1;
	}
	p1.d[0].c = red;
	p1.d[1].c = cyan;
	p1.d[2].c = magenta;

	display_packet(p1);

	char *buffer = (char *)malloc(sizeof(header) + p1.h.qty * sizeof(data));
	if (NULL == buffer)
	{
		printf("Error while allocating buffer.\n");
		return 1;
	}

	// TODO: send : compute the checksum of the data area and store the value in p.h.checksum
	// TODO: receive : compute the checksum of the data area and compare with the field checksum of the header
	send(p1, buffer);
	receive(buffer, &p2);
	puts("...");
	display_packet(p2);
	return 0;
}