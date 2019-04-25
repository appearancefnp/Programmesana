#include "kartot.h"
#define NULL nullptr

void kartot(node* &p, node* &last) {
    if (p == NULL) return;
    node* run0 = NULL;
    node* run1 = p;
    while (run1->next != NULL) {
        if (run1->info > run1->next->info) {
            ///UZLIEK LAST POINTERI UZ LIELAKO ELEMENTU
            if (last->info < run1->info) last=run1;
            ///SAMAINA VIETAM JA NAKAMAIS IR MAZAKS
            node * tmp = run1->next->next;
            node * tmp2 = run1->next;
            run1->next->next = run1;
            run1->next = tmp;
            ///JA RUN0 SKATAS UZ NODE, TAD IESTATIT POINTERI UZ NOMAINITO NODE
            if (run0 != NULL) {
                run0->next = tmp2;
            } else {
                ///JA NE, TAD FIRST SKAT�S UZ NOMAIN�TO NODE
                p = tmp2;
            }
            ///IESTAT�M RUNNERUS NO LIST S�KUMA, LAI TURPIN�TU MAIN�TS
            run0 = NULL;
            run1 = p;
        } else {    ///JA NEIZPILD�S, TAD PAB�DAM RUNNERUS UZ N�KAMO POZ�CIJU
            run0 = run1;
            run1 = run1->next;
        }
    }
    return;
}
