#include "mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	t_data	img;
	int i = 0;
	int x = 5;
	int y = 5;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 600, "so_long");
	img.img = mlx_new_image(mlx_ptr, 500, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	while(i < 500)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		i++;
		x++;
		y++;
	}
	i = 0;
	x = 500;
	y = 5;

	while(i < 500)
	{
		my_mlx_pixel_put(&img, x, y ,0x00FF0000);
		i++;
		x--;
		y++;

	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}

