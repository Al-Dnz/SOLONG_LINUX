#include "solong.h"

void	process(t_state *state)
{
	draw_map(state);
	mlx_hook(state->win, 17, 0, quit, state);
	mlx_hook(state->win, 2, 1L << 0, &keypress, state);
	mlx_key_hook(state->win, move_p, state);
	mlx_loop_hook(state->mlx, &period_process, state);
	mlx_loop(state->mlx);
}

int	main(int argc, char **argv)
{
	char	*path;
	t_state	state;

	set_parse_flag(&state);
	path = argv[1];
	arg_error(argc, argv);
	state.map_width = map_width(path);
	state.map_height = map_height(path);
	printf("MAP : width = [%d] height = [%d]\n",
		state.map_width, state.map_height);
	state.map = array_generator(state.map_width, state.map_height);
	fill_map(state.map, path, 0, 0);
	map_analyzer(&state);
	map_diagnostic(&state);
	display_map(state.map);
	if (map_validation(&state) == 0)
		quit(&state, state.error);
	else
		ft_putstr_fd("=>OK<=\n", 1);
	printf("player : X[%d]Y[%d]\n", state.player_coord.x, state.player_coord.y);
	set_game_flag(&state);
	init_window(&state);
	set_main_texture(&state);
	process(&state);
	return (1);
}
