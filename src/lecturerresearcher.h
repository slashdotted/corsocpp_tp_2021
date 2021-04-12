#include <string>
#include "lecturer.h"
#include "researcher.h"
#ifndef LECTURERRESEARCHER
#define LECTURERRESEARCHER

class LecturerResearcher : public Lecturer, public Researcher  {
public:
    LecturerResearcher(const std::string& name,
                    const std::string& institute,
                    int nr,
                    const std::string& studies,
                    const std::string& course,
                    const std::string& researcharea,
                    double researchpercentage);

    double researchpercentage() const;

    std::string classname() const;

protected:
    double m_researchpercentage;
};

#endif