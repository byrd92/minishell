#include "../minishell.h"

int     ft_output(t_mini *mini)
{
    t_token *content;
    int     newout;

    newout = 0;
    while (mini->tokens)
	{
		content = (t_token *)mini->tokens->content;
		if (content->type == 3)
		{
            mini->newout = open(content->argv[0],O_CREAT|O_TRUNC|O_WRONLY, 0644);
            dup2(mini->newout, 1);

        }
		mini->tokens = mini->tokens->next;
	}
    return (0);
}


