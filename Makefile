#Compiler settings.
#Change according to your system compiler

CC:= gcc
CXXFLAGS:= -std=gnu11 -Wall 
EXT:=.c


#modify at will..

APPNAME:= Batch2k19

#Don't touch anything below

SRCDIR:=src
OBJDIR:=obj
DEPDIR:=deps

src:=$(wildcard $(SRCDIR)/*$(EXT))
obj:=$(src:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
deps:=$(obj:$(OBJDIR)/%.o=$(DEPDIR)/%.d)


all: $(APPNAME)
	

$(APPNAME): $(obj)
	$(CC) $(CXXFLAGS) -o $@ $^

$(DEPDIR)/%.d: $(SRCDIR)/%.c
	$(CC) $(CXXFLAGS) $< -MM -MT $(@:$(DEPDIR)/%.d=$(OBJDIR)/%.o) > $@

-include $(deps)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CXXFLAGS) -o $@ -c $<



clean:
	del *.exe
	cd obj && del *.o && cd ../
	cd deps && del *.d && cd ../