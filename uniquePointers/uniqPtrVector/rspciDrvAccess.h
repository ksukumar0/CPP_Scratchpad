#ifndef RSPCIDRVACCESS_H
#define RSPCIDRVACCESS_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>

class CRsPciDriverAccess
{
   private:
      std::vector<std::unique_ptr<int>> m_sg_tables;
      std::vector<std::unique_ptr<double>> m_sgInfo;
      std::string m_text;

   public:
      CRsPciDriverAccess(CRsPciDriverAccess&& );
      CRsPciDriverAccess(std::string& path);
      ~CRsPciDriverAccess();
};

#endif
