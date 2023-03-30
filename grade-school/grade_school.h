#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <map>
#include <vector>
#include <algorithm>
namespace grade_school
{
using namespace std;
class school
{
public:
    typedef vector<string> grade_t;
    typedef map<int, grade_t> roster_t;
    school()  = default;
    ~school() = default;

    inline const roster_t& roster() const
    {
        return m_roster;
    }

    inline const grade_t grade(int const&& grade) const
    {
        if ( m_roster.find(grade) != m_roster.end() )
        {
            return m_roster.at(grade);
        }
        else
        {
            return {};
        }
    }

    void add(string const&& name, int const&& grade)
    {
        auto position = upper_bound(m_roster[grade].begin(),
                                    m_roster[grade].end(),
                                    name);

        m_roster[grade].insert(position, name);
    }
private:
    roster_t m_roster;
};
} // namespace grade_school

#endif // GRADE_SCHOOL_H
