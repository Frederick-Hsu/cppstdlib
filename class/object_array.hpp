#ifndef OBJECT_ARRAY_HPP
#define OBJECT_ARRAY_HPP

    #include <string>

    class IBuffer;

    class IBuffer
    {
    private:
        std::string buf;
    public:
        IBuffer();
        ~IBuffer();
    };

    void init_object_array();

#endif  /* OBJECT_ARRAY_HPP */