さらばmemory leak

```
void	*ft_malloc(int size);
void	ft_free_all(void);
```

ft_malloc()によってmallocされたものは、ft_free_all()によって全てfreeされます。
使い方としては、mallocの代わりにft_malloc()を使い、プログラムの途中ではfreeせず、プログラムの最後にft_free_all()を呼びます。

注意： ft_malloc()によってmallocしたものをft_free_all()以外でfreeするとdouble freeが起こります。
注意： static変数が禁止されている場合は使用できません。
注意： get_next_lineのように、mallocとfreeを行う回数に上限がない場合などには使わないようにしましょう（例えレビューや機械判定は乗り切れるとしても）


↓こんなプログラムでもno memory leak!

```
#include <stdlib.h>
#include "ft_malloc.h"

void	func()
{
	int	*p;

	p = ft_malloc(sizeof(int) * 5);
	ft_malloc(sizeof(char **) * 20);
}

int main(void)
{
    char    *s;

    s = ft_malloc(100);
    func();
	ft_free_all();
}
```

ft_malloc()したけどプログラムの途中でそれだけfreeしたい場合のための関数ft_free(void *p)が欲しいとなったら作ります。
バグがあったら教えてください。
