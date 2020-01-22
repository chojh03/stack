#include <stdio.h>
#include <string.h>

int *stack[100];
int eax=0,ebx=0,ecx=0,edx=0,esi=0,edi=0; //register
int **ebp=0,**esp=0; //stack control register
int *eip = 0;

void view_reg_status() {
	printf("EAX : 0x%x\n",eax);
	printf("EBX : 0x%x\n",ebx);
	printf("ECX : 0x%x\n",ecx);
	printf("EDX : 0x%x\n",edx);
	printf("ESI : 0x%x\n",esi);
	printf("EDI : 0x%x\n",edi);
	printf("EBP : 0x%x\n",ebp);
	printf("ESP : 0x%x\n",esp);
	printf("EIP : 0x%x\n\n",eip);
}

void debug(int *data){
	printf("[DEBUG] data : 0x%x\n",data);
}

void call(int *addr) {
	eip = addr;
}

void func_prologue() {
	push("ebp");
	ebp = esp;
}

void leave() {
	esp = ebp;
	pop("ebp");
}	

void input_stack(char *str,int length) {;
	int len = 0;	

	func_prologue();	

	if(length < 4) {
		esp = esp - 1;
		strcpy(esp,(int **)str);
		leave();
		return;
	}
	
	else if(length>4 && length%4 != 0) {
		len = ((length + (4 - (length % 4))) / 4);
		esp = esp - len;
		strcpy(esp,str);
		leave();
		return;
	}

	else if(length>4 && length%4 == 0) {
		len = (length / 4);
		esp = esp - len;
		strcpy(esp,str);
		leave();
		return;
	}
}

void push(char *reg) {
	if(strcmp(reg,"eax") == 0)
	{
		esp = esp-1;
		*esp = (int *)eax;
		return;
	}

	else if(strcmp(reg,"ebx") == 0)
        {
                esp = esp-1;
                *esp = (int *)ebx;
		return;
        }

	else if(strcmp(reg,"ecx") == 0)
        {
                esp = esp-1;
                *esp = (int *)ecx;
		return;
        }

	else if(strcmp(reg,"edx") == 0)
        {
                esp = esp-1;
                *esp = (int *)edx;
		return;
        }

	else if(strcmp(reg,"esi") == 0)
        {
                esp = esp-1;
                *esp = (int *)esi;
		return;
        }

	else if(strcmp(reg,"edi") == 0)
        {
                esp = esp-1;
                *esp = (int *)edi;
		return;
        }

	else if(strcmp(reg,"ebp") == 0)
	{
		esp = esp - 1;
		*esp = (int *)ebp;
		return;
	}

	else
		return;

}

void pop(char *reg) {
	if(strcmp(reg,"eax") == 0)
        {
		eax = (int)*esp;
                esp = esp+1;
                return;
        }

        else if(strcmp(reg,"ebx") == 0)
        {
		ebx = (int)*esp;
                esp = esp+1;
                return;
        }

        else if(strcmp(reg,"ecx") == 0)
        {
		ecx = (int)*esp;
                esp = esp+1;
                return;
        }

        else if(strcmp(reg,"edx") == 0)
        {
		edx = (int)*esp;
                esp = esp+1;
                return;
        }

        else if(strcmp(reg,"esi") == 0)
        {
		esi = (int)*esp;
                esp = esp+1;
                return;
        }

        else if(strcmp(reg,"edi") == 0)
        {
		edi = (int)*esp;
                esp = esp+1;
                return;
        }

	else if(strcmp(reg,"ebp") == 0)
        {
                ebp = *esp;
                esp = esp+1;
                return;
        }

	else if(strcmp(reg,"eip") == 0)
        {
                eip = *esp;
                esp = esp+1;
                return;
        }
}

int main(void)
{
	ebp = &stack[100];	
	esp = &stack[100];		
}