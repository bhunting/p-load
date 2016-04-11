#pragma once

class ArgReader
{
public:
    ArgReader(int argc, char ** argv) : argv(argv), argc(argc), index(0)
    {
    }

    ArgReader() : argv(NULL), argc(0), index(0)
    {
    }

    // Advance and return the current argument, or null if we have reached the end.
    // The first call of this returns argv[1] because argv[0] is just the program name.
    const char * next()
    {
        if (index < argc)
        {
            index++;
            return argv[index];
        }
        else
        {
            return NULL;
        }
    }

    // Return the argument before the current one, or NULL.
    const char * last() const
    {
        if (index > 0)
        {
            return argv[index - 1];
        }
        else
        {
            return NULL;
        }
    }

    void rewind()
    {
        if (index > 0)
        {
            index--;
        }
    }

private:
    char ** argv;
    int argc;
    int index;
};
