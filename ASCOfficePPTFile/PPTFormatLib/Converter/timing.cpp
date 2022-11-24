#include "timing.h"

#include "Animation/intermediate_anim.h"
#include "Animation/Timing_1995.h"
#include "Animation/Timing_2010.h"
#include "Animation/TimingExeption.h"
#include "Animation/hashcode10.h"   // not work correct


using namespace PPT::Converter;

Timing::Timing(const Intermediate::SlideAnimation& slideAnim, const std::unordered_set<int> &shapesID) :
    slideAnim(slideAnim),
    shapesID(shapesID)
{}

PPTX::Logic::Timing Timing::Convert(CExMedia *pExMedia, CRelsGenerator *pRels)
{
//    this->pExMedia = pExMedia;
//    this->pRels = pRels;

    Timing_1995(slideAnim.arrAnim_1995).
            Convert(timing, pExMedia, pRels);
    bool isValidHash = HashCode10().IsValidHash(slideAnim);

    try {
        Timing_2010(slideAnim.pAnim_2010, shapesID).
                Convert(timing, pExMedia, pRels);
    } catch (const TimingExeption &ex) {
    } catch (...) {
    }

    if (timing.bldLst.IsInit() && timing.bldLst->list.empty())    // You can't leave an empty tag <p:bldLst/>
        timing.bldLst.reset();

    return std::move(timing);
}
