class CriticalSection
{
    CRITICAL_SECTION m_critSec;
    public:
    CriticalSection();
    ~CriticalSection();
    
    void Lock();
    void UnLock();
};

class CriicalSectionLock
{
    CriticalSection* m_pCritSec;
    public:
    CriticalSectionLock(CriticalSection& critSec);
    ~CriticalSectionLock();
};

CriticalSection::CriticalSection()
{
    InitializeCriticalSectionEx(&m_critSec,0,0);
}
// :: in C++ 범위 지정 연산자.

CriticalSection::~CriticalSection()
{
    DeleteCriticalSection(&m_critSec);
}
