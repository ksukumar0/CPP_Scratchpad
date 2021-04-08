template <class ICAP> class CMdFpgaIcap;

class IMdFpgaIcap
{
public:
   template <class ICAP>
   static IMdFpgaIcap* createICapControl(ICAP* a_pRLIcap, uint32_t a_udwWaitTimeAfterReconfig_ms = 0, bool a_bCheckStatus = true, bool a_bSwitchToFallBack = false)
   {
      return new CMdFpgaIcap<ICAP>(a_pRLIcap, a_udwWaitTimeAfterReconfig_ms, a_bCheckStatus, a_bSwitchToFallBack);
   }
   virtual bool ReconfigureFpgaWithICap(void) = 0;

   virtual ~IMdFpgaIcap() {};
};

/* CLASS DECLARATION **********************************************************/
/** ICap Control class. Accessing the ICap Interface.
    As this Xilinx interface is identical for all FPGAs a templete class is used.
    So this class can be used for each FPGA.
    Implementation based on: <doc_view>:\Merkur_EC\HW\Digitale_HW\Matlab\IB_Tests\Tools\Reconfig_FPGA.m
*******************************************************************************/
template <class ICAP>
class CMdFpgaIcap : public IMdFpgaIcap
{
public:
   // Constructor
   CMdFpgaIcap(ICAP* a_pICap, uint32_t a_udwWaitTimeAfterReconfig_ms, bool a_bCheckStatus, bool a_bSwitchToFallBack);
   // Destructor
   virtual ~CMdFpgaIcap() override {} ;

   virtual bool ReconfigureFpgaWithICap(void) override;
private:
   const ICAP*    m_pRlIcap;
   bool           m_bCheckStatus;                  // Only required for ICAPE3-Cell in Kintex UltraScale FPGA
   uint32_t       m_udwWaitTimeAfterReconfig_ms;   // FPGA specific time after reconfiguration, before the FPGA responds again
   bool           m_bSwitchToFallBack;             // True when the fall back FPGA version shall be seletcted for the next boot

   bool ProgramICap(uint32_t a_udwValue);
   bool WaitForICap();
};
