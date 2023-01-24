namespace XHW{
   class CONTROL{
      public:
         static constexpr const int s_sigMiq_on  = 0;
         static constexpr const int s_sigIn1_on  = 1;
         static constexpr const int s_sigOut1_on = 2;
         static constexpr const int s_sigOut2_on = 3;
         static constexpr const int s_sigOut3_on = 4;
         static constexpr const int s_sigContmem_on = 5;

         enum class MIQ_ON: uint32_t
      {
         /** Signal value OFF: Disabled, not active. **/
         OFF = 0,
         /** Signal value ON: Enabled, active. **/
         ON = 1
      };

         enum class IN1_ON: uint32_t
      {
         /** Signal value OFF: Disabled, not active. **/
         OFF = 0,
         /** Signal value ON: Enabled, active. **/
         ON = 1
      };

         enum class OUT1_ON: uint32_t
      {
         /** Signal value OFF: Disabled, not active. **/
         OFF = 0,
         /** Signal value ON: Enabled, active. **/
         ON = 1
      };

         enum class OUT2_ON: uint32_t
      {
         /** Signal value OFF: Disabled, not active. **/
         OFF = 0,
         /** Signal value ON: Enabled, active. **/
         ON = 1
      };

         enum class OUT3_ON: uint32_t
      {
         /** Signal value OFF: Disabled, not active. **/
         OFF = 0,
         /** Signal value ON: Enabled, active. **/
         ON = 1
      };

         enum class CONTMEM_ON: uint32_t
      {
         /** Signal value OFF: Disabled, not active. **/
         OFF = 0,
         /** Signal value ON: Enabled, active. **/
         ON = 1
      };

         template <class ValType>
            static constexpr const int * GetSignalByType()
            {
               if constexpr (std::is_same<ValType, MIQ_ON>::value) return &s_sigMiq_on;
               if constexpr (std::is_same<ValType, IN1_ON>::value) return &s_sigIn1_on;
               if constexpr (std::is_same<ValType, OUT1_ON>::value) return &s_sigOut1_on;
               if constexpr (std::is_same<ValType, OUT2_ON>::value) return &s_sigOut2_on;
               if constexpr (std::is_same<ValType, OUT3_ON>::value) return &s_sigOut3_on;
               if constexpr (std::is_same<ValType, CONTMEM_ON>::value) return &s_sigContmem_on;
               return nullptr;
            }

         template<class SignalValType, class = std::enable_if_t<GetSignalByType<SignalValType>() != nullptr>>
            CONTROL& operator << (const SignalValType value)
            {
               constexpr const int &signal = *(GetSignalByType<SignalValType>());
               std::cout<<"Signal value is "<<signal<<"\n";
               return *this;
            }

   };
};
