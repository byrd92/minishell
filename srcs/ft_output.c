#include "../minishell.h"

int     ft_output(t_mini *mini)
{
    t_token *content;
    t_list  *token;

    token = mini->tokens;
    while (token)
	{
		content = (t_token *)token->content;
		if (content->type == 3)
		{
            mini->newout = open(content->argv[0],O_CREAT|O_TRUNC|O_WRONLY, 0644);
            dup2(mini->newout, 1);
            return (1);
        }
		token = token->next;
	}
    return (0);
}


