class String
{
    char *data;
    int len;

public:
    static int StrLen(const char *);

private:
    String(const char *, int, const char *, int);
    void MoveTo(String *src)
    {
        src->data = data;
        src->len = len;
        data = 0;
    }

public:
    ~String()
    {
        if (data)
            delete data;
    }

    String()
    {
        data = new char[1];
        data[len = 0] = 0;
    }
    String(const char *s)
    {
        String temp(s, StrLen(s), 0, 0);
        temp.MoveTo(this);
    }
    String(const String &s)
    {
        String temp(s.data, s.len, 0, 0);
        temp.MoveTo(this);
    }
public:
    int Length() const
    {
        return len;
    }
    String& ToLower();
public:
    operator char *()
    {
        return data;
    }

    char& operator[](int index)
    {
        return data[index];
    }

    String& operator=(const String &right)
    {
        String temp(right.data, right.len, 0, 0);
        delete[] data;
        temp.MoveTo(this);

        return *this;
    }

    friend String operator+(const String &left,
                            const String &right)
    {
        return String(left.data, left.len, right.data, right.len);
    }
    friend String operator+(const String &left,
                            const char c)
    {
        return String(left.data, left.len, &c, 1);
    }
};

int String::StrLen(const char *s)
{
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

// Hàm tạo từ 2 mảng ký tự
String::String(const char *s1, int l1, const char *s2, int l2)
{
    len = l1 + l2;
    data = new char[len + 1];
    data[len] = '\0';

    char *p = data;
    for (int i = 0; i < l1; i++, p++) *p = s1[i];
    for (int i = 0; i < l2; i++, p++) *p = s2[i];
}

String& String::ToLower()
{
    for (int i = 0; i < len; i++)
    {
        char c = data[i];
        if (c >= 'A' && c <= 'Z')
            data[i] = c + ' ';
    }
    return *this;
}

void main()
{
    {
        String s1 = "ABC";
        String s2;
        s2 = s1;
        String s3 = s2 + "123" + '\n';

        cout << s3.ToLower() << endl;
    }

    system("pause");
}
